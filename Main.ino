#include "Button.h"
#include "dhtesp.h"
#include <Preferences.h>
#include <HTTPClient.h>
#include "RESTFUL.h"
#include <SD.h>
#include <SPI.h>
#include <FS.h>
#include "time.h"

#define DHTPIN 27
#define DHTTYPE DHTesp::DHT11

enum ledState {
	LED_GREEN, LED_AMBER, LED_RED, LED_START
};

enum systemState {
	SYS_READY, SYS_WAIT
};

enum occupiedState {
	ROOM_OCCUPIED, ROOM_VACANT, ROOM_UNREADY
};

enum intervalTime {
	T_5, T_10, T_30, T_60, T_2M, T_5M
};

enum sdState {
	SD_IN, SD_OUT
};

enum fileState {
	FILE_MISSING, FILE_CREATED
};

ButtonState btnCurrent;

//Pin numbers
const int SWITCH_PIN = 13;
const int POTIN_PIN = 12; // CHANGED THIS
const int PIR_PIN = 14;
const int CS_PIN = 5;

//WiFi Pass and SSID
const char *PASS = "d24d92ac6b";
const char *SSID = "PLUSNET-HZMT";

//NTP Server
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0; // UTC:00 Offset (London Timezone)
const int daylightOffset_sec = 3600; // Daylight savings time

//Global counters
int interval = 5000;
int sdCount = 0;
int potCount = 0;
int pirCount = 0;

//Set button
Button *button = NULL;

//set various system states
ledState ledCurrentState;
systemState sysState = SYS_WAIT;
occupiedState occupiedStatus = ROOM_VACANT;
intervalTime intervalTimer = T_5;

//LED Settings
int rgbLedArray[3] = { 1, 2, 3 };
const int ledR = 26, ledG = 33, ledB = 25;
int R, G, B;

//global timer - poor method, look for other implementations
long currentTime, dhtTimer, pirTimer, pirLongTimer, pirSysCheck, stringTimer,
		volatylerTimer, remoteTimer, btnTimer, wifiRepeateTimer,
		buzzerAlertTimer, buzzerSoundTimer, snoozeTimer;

//DHT11 SENSOR Vars
float humid;
float temp;
DHTesp dht;

//Buzzer setup
int buzzerChannel = 0;
int buzzerFRQ = 2000;
int buzzerPin = 32;
int buzzerInterval = 0;
bool buzzerOn = false;
bool buzzerEnabled = false;
bool snoozeState = false;
ledState ledBuzzerCompare = LED_START;

//Global string out
String stringOut;

//Global BOOL
boolean pirReady = false;
boolean wifiReady = false;

//Preference setup
Preferences preferences;

WiFiServer server; // @suppress("Abstract class cannot be instantiated")

RESTFUL rest;

//SD Setup
File file; // @suppress("Abstract class cannot be instantiated")
String fileName = "/readings.txt";
String readingsArray[24];
int arrayIndex;

void setup() {

	//Initialize SD Card
	SD.begin(CS_PIN);

	// Initialize SD File
	File initFile = SD.open("/readings.txt"); // @suppress("Abstract class cannot be instantiated")
	if (!initFile) {
		// File doesn't exist
		// Creating file
		createFile("/readings.txt");
	}

	//Connect DHT library to the DHT pin
	dht.setup(DHTPIN, DHTesp::DHT11);

	//Attach the LED pins to a channel
	ledcAttachPin(ledR, 1);
	ledcAttachPin(ledG, 2);
	ledcAttachPin(ledB, 3);
	ledcAttachPin(buzzerPin, 0); //And Buzzer

	//Attach the Channel with a 12khz PWM and 8-bit resolution
	ledcSetup(1, 12000, 8);
	ledcSetup(2, 12000, 8);
	ledcSetup(3, 12000, 8);
	ledcSetup(buzzerChannel, buzzerFRQ, 8); //And Buzzer at 2khz

	//Attach the PIR sensor pin
	pinMode(PIR_PIN, INPUT);

	//Attach the button to the switch pin
	button = new Button(SWITCH_PIN);

	//Test RGB LED
	for (int i = 0; i < 3; i++) {
		ledcWrite(rgbLedArray[i], 255);
		delay(1000);
		ledcWrite(rgbLedArray[i], 0);
	}

	//Begin Serial listener
	Serial.begin(115200); // @suppress("Ambiguous problem")

	//Initialise the timer variables
	dhtTimer = 0;
	pirTimer = 0;
	pirLongTimer = 0;
	stringTimer = -5100;
	volatylerTimer = 0;
	remoteTimer = 0;
	pirSysCheck = 0;
	buzzerAlertTimer = 0;
	buzzerSoundTimer = 0;
	snoozeTimer = 0;
//	//preference setter
//	preferences.begin("localData", false);
//	stringOut = preferences.getString("mainOut", "Empty");

	Serial.print("Connecting to ");
	Serial.println(SSID);
	WiFi.begin(SSID, PASS);

	sysCheck();
	server.begin(1337);
}

// The loop function is called in an endless loop
void loop() {

	currentTime = millis();

	//WifiCheck
	wifiReadyCheck();

	//wifi Server Check -- Probably change or remove this
	wifiServerCheck();

	//Feature SET B
	sensorRead();
	ledSwitch();

	//Feature Set D
	pirSensorRead();

	//String Creator
	finalStringOut();

	//Feature Set E
	localStringStorage();

	//Feature SET C, E, F
	dataOut();

	//Feature Set G

	if (occupiedStatus == ROOM_OCCUPIED) {
		buzzerControl();
		if (buzzerOn == true) {
			buzzerSound();
		}

	} else {
		ledcWrite(0, 0);
		buzzerOn = false;
	}

	ButtonState btnRead = button->checkState();
	potCount = analogRead(POTIN_PIN);
	if (btnRead != btnCurrent) {
		btnCurrent = btnRead;
		switch (btnCurrent) {
		case ButtonState::ON:
			btnTimer = millis();
			break;
		case ButtonState::OFF:
			buttonTimeCheck();
			break;
		}
	}

}

void wifiReadyCheck() {
	if (wifiReady == false) {
		if ((millis() - wifiRepeateTimer) >= 5000) {
			if (WiFi.status() == WL_CONNECTED) {
				wifiReady = true;
				Serial.print("Connected as : ");
				Serial.println(WiFi.localIP());

				//Initialize local epoch/time
				configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

			} else {
				Serial.print("Not Connected");
				//WiFi.begin(SSID, PASS);
				WiFi.reconnect();
			}
			wifiRepeateTimer = millis();
		}
	} else if (WiFi.status() == WL_DISCONNECTED) {
		wifiReady = false;
	}
}

void wifiServerCheck() {
	WiFiClient client = server.available(); // @suppress("Abstract class cannot be instantiated")
	if (client) {
		delay(100);
		rest.handleClient(client);
		client.stop();
		Serial.println("--- Disconnected Client");
	}
}

void buttonTimeCheck() {
	if ((millis() - btnTimer) >= 1000) {
		intervalSwitch();
	} else {
		//Snooze
		snooze();
	}
}

void intervalSwitch() {
	switch (intervalTimer) {
	case 0:
		interval = 5000;
		intervalTimer = T_10;
		break;
	case 1:
		interval = 10000;
		intervalTimer = T_30;
		break;
	case 2:
		interval = 30000;
		intervalTimer = T_60;
		break;
	case 3:
		interval = 60000;
		intervalTimer = T_2M;
		break;
	case 4:
		interval = 120000;
		intervalTimer = T_5M;
		break;
	case 5:
		interval = 300000;
		intervalTimer = T_5;
		break;
	}
	Serial.print("Debug Interval Timer switched to: ");
	Serial.print(interval / 1000);
	Serial.println("s");
}

void snooze() {
	if (snoozeState == false) {
		Serial.println("Snoozing Current Alert");
		snoozeState = true;
		snoozeTimer = millis();
	} else {
		Serial.println("Alert Already Snoozed");
	}

}

void buzzerControl() {

	if (ledCurrentState == LED_GREEN && ledBuzzerCompare != ledCurrentState) {
		buzzerEnabled = false;
		buzzerAlertTimer = millis();
		Serial.println("Changed 1");
		ledBuzzerCompare = ledCurrentState;
		snoozeState = false;
	} else if (ledCurrentState == LED_AMBER
			&& ledBuzzerCompare != ledCurrentState) {
		buzzerEnabled = true;
		buzzerInterval = 30000;
		buzzerAlertTimer = millis();
		Serial.println("Changed 2");
		ledBuzzerCompare = ledCurrentState;
		snoozeState = false;
	} else if (ledCurrentState == LED_RED
			&& ledBuzzerCompare != ledCurrentState) {
		buzzerEnabled = true;
		buzzerInterval = 5000;
		buzzerAlertTimer = millis();
		Serial.println("Changed 3");
		ledBuzzerCompare = ledCurrentState;
		snoozeState = false;
	}





	if (snoozeState == true && ((millis() - snoozeTimer) >= 120000)) {
		Serial.println("Snooze over");
		snoozeState = false;
	}else if (snoozeState == false){
		if ((millis() - buzzerAlertTimer) >= buzzerInterval
					&& buzzerEnabled == true) {
				buzzerOn = true;
				ledcWrite(0, 125);
				buzzerSoundTimer = millis();
				buzzerAlertTimer = millis();

			}
	}
}

void buzzerSound() {
	if ((millis() - buzzerSoundTimer) >= 1000) {
		ledcWrite(0, 0);
		buzzerOn = false;
	}
}

//Feature A - CHECK SYS STATE
void sysCheck() {
	long waitingTimer = millis();
	bool dhtSens = false, wifiEscape = false, remoteCon = false;
	Serial.println("System is getting Ready");
	while (sysState == SYS_WAIT) {
		//SENSOR CHECK
		if (!isnan(humid) && !isnan(temp)) {
			dhtSens = true;
		}

		//Start the 60 seconds PIR timer
		pirSysCheck = millis();

		//True if wifi is connected else true with a new timer
		if (WiFi.status() == WL_CONNECTED && wifiEscape != true) {
			wifiEscape = true;
		} else {
			wifiRepeateTimer = millis();
			wifiEscape = true;
			Serial.println("The system will run without wifi.");
		}

		//REMOTE STORAGE
		remoteCon = true;

		if (dhtSens && wifiEscape && remoteCon) {
			sysState = SYS_READY;
		}

		if ((millis() - waitingTimer) >= 2000) {
			Serial.print(" DHT: ");
			Serial.print(dhtSens);
			Serial.print(" WiFi: ");
			Serial.print(wifiEscape);
			Serial.print(" SD: ");
			Serial.println(remoteCon);
			waitingTimer = millis();
		}

	}
	//System is now ready
	Serial.println("System State has changed to SYS_READY");

	if (wifiReady == true) {
		Serial.print("Connected as : ");
		Serial.println(WiFi.localIP());
	}

	Serial.println("SYSTEM BEGIN");
	//Print out the locally stored value
//
//	Serial.print("Local Store: ");
//	dataOut();

}

void sensorRead() {

// read the value of the sensors and set them to variables
	if ((millis() - dhtTimer) >= 2000) {
		TempAndHumidity newValues = dht.getTempAndHumidity();
		humid = newValues.humidity;
		temp = newValues.temperature;
		dhtTimer = millis();
		if (isnan(humid) || isnan(temp)) {
			Serial.println(F("Failed to read from DHTesp sensor!"));
			return;
		}
	}

}

void ledSwitch() {
//switch the colour of the LED depending on variables
	if ((temp >= 18 && temp <= 23) && (humid >= 35 && humid <= 60)) {
		//Set colour Green
		R = 0;
		G = 255;
		B = 0;
		ledCurrentState = LED_GREEN;
	} else if ((temp >= 16 && temp <= 27) && (humid >= 25 && humid <= 75)) {
		//Set Colour Amber
		R = 255;
		G = 80;
		B = 0;
		ledCurrentState = LED_AMBER;
	} else {
		//Set Colour Red
		R = 255;
		G = 0;
		B = 0;
		ledCurrentState = LED_RED;
	}

	ledcWrite(1, R);
	ledcWrite(2, G);
	ledcWrite(3, B);
}

void pirSensorRead() {

	if (pirReady == true) {
		if ((millis() - pirTimer) >= 1000) {
			if (digitalRead(PIR_PIN) == HIGH) {
				occupiedStatus = ROOM_OCCUPIED;
				pirLongTimer = millis();
			} else if (digitalRead(PIR_PIN == LOW)
					&& occupiedStatus != ROOM_VACANT) {
				if ((millis() - pirLongTimer) > 60000) {
					occupiedStatus = ROOM_VACANT;
					Serial.println("Room VACANT");

				}

			}
			pirTimer = millis();
		}
	} else if ((millis() - pirSysCheck) >= 10000) {
		pirReady = true;
		occupiedStatus = ROOM_UNREADY;
	}
}

void localStringStorage() {

}

void finalStringOut() {
	/* Humidity
	 * Temp
	 * LED state
	 * PIR state
	 * Output interval
	 * Alert status + snooze
	 *
	 * */

	stringOut = "Running Time: " + String(millis()) + "ms ";
	stringOut += "Local Time: " + returnLocalTime();
	stringOut += " Humidity: " + String(humid) + " Temperature: "
			+ String(temp);
	stringOut += " LED state: " + String(ledCurrentState);
	if (pirReady == false) {
		stringOut += " PIR state: Warming";
	} else {
		stringOut += " PIR state: " + String(occupiedStatus);
	}
	stringOut += " Interval Time: " + String(interval / 1000) + "s";
	if (buzzerInterval == 0) {
		stringOut += " Buzzer Interval: Not Active";
	} else if (snoozeState == true) {
		stringOut += " Buzzer Interval: Snoozing";
	} else {
		stringOut += " Buzzer Interval: " + String(buzzerInterval / 1000) + "s";
	}

	if (wifiReady == false) {
		stringOut += "   (WiFi is currently not connected)";
	}
}

void dataOut() {
	long timerCheck = interval;

	if (interval < 30000) {
		timerCheck = 30000;
	}

	//Printing the debug String
	if ((millis() - stringTimer) >= interval) {
		Serial.println(stringOut);
		stringTimer = millis();

	}

	//Setting volatile output
	if ((millis() - volatylerTimer) >= interval) {
//		preferences.putString("mainOut", stringOut);
		readingsArray[arrayIndex] = stringOut;
		volatylerTimer = millis();
		arrayIndex++;
	}

	//Setting remote output
	if ((millis() - remoteTimer) >= timerCheck) {

		WiFiClient client; // @suppress("Abstract class cannot be instantiated")
		rest.GET(client, stringOut);

		remoteTimer = millis();
	}

	if ((millis() - sdCount) >= 30000) {
		file = SD.open("/readings.txt", FILE_APPEND);
		for (String reading : readingsArray) {
			if (!reading.equals("")) {
				if (file.println(reading)) {
					//It worked
				} else {
					Serial.println("Append failed");
				}
			}

		}
		file.close();
		arrayIndex = 0;

		for (int i = 0; i <= 24; i++) {
			readingsArray[i] = "";
		}
		sdCount = millis();
	}
}

String returnLocalTime() {
	struct tm timeinfo;
	if (!getLocalTime(&timeinfo)) {
		return "Failed to obtain time";
	}

	char timeStringBuff[50]; //50 chars should be enough

	strftime(timeStringBuff, sizeof(timeStringBuff), "%B %d %Y %H:%M:%S",
			&timeinfo);

	//Construct String object
	String asString(timeStringBuff);

	return asString;
}

// https://randomnerdtutorials.com/esp32-data-logging-temperature-to-microsd-card/
void createFile(String dir) {
	File file = SD.open(dir, FILE_WRITE); // @suppress("Abstract class cannot be instantiated")

	if (!file) {
		Serial.println("File can't be written.");
		return;
	}

	if (file.print("")) {
		Serial.println("Write Succeeded!.");
	} else {
		Serial.println("Write Failed.");
	}

	file.close();
}
