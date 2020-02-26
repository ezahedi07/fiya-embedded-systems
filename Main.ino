#include "Button.h"
#include "dhtesp.h"
#include <Preferences.h>
//#include "SD.h"

#define DHTPIN 27
#define DHTTYPE DHTesp::DHT11

enum ledState {
	LED_GREEN, LED_AMBER, LED_RED

};

enum systemState {
	SYS_READY, SYS_WAIT
};

enum occupiedState {
	ROOM_OCCUPIED, ROOM_VACANT
};

enum intervalTime {
	T_5, T_10, T_30, T_60, T_2M, T_5M
};

ButtonState btnCurrent;

//Pin numbers
const int SWITCH_PIN = 13;
const int POTIN_PIN = 12; // CHANGED THIS
const int PIR_PIN = 14;

//Global counters
int interval = 5000;
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

//global timer - poor method, look for other implimentations
long currentTime, dhtTimer, pirTimer, pirLongTimer, stringTimer, volatylerTimer, remoteTimer, btnTimer;

//DHT11 SENSOR Vars
float humid;
float temp;
DHTesp dht;

//Global string out
String stringOut;

//Preference setup
Preferences preferences;

void printOut() {
	Serial.println("PIR HIGH");
}

void setup() {

	//Connect DHT library to the DHT pin
	dht.setup(DHTPIN, DHTesp::DHT11);

	//Attach the LED pins to a channel
	ledcAttachPin(ledR, 1);
	ledcAttachPin(ledG, 2);
	ledcAttachPin(ledB, 3);

	//Attach the Channel with a 12khz PWM and 8-bit resolution
	ledcSetup(1, 12000, 8);
	ledcSetup(2, 12000, 8);
	ledcSetup(3, 12000, 8);

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

	//PIR interrupt
	//attachInterrupt(digitalPinToInterrupt(PIR_PIN), printOut, RISING);

	//Begin Serial listener
	Serial.begin(115200);

	//Initialise the timer variables
	dhtTimer = 0;
	pirTimer = 0;
	pirLongTimer = 0;
	stringTimer = -5100;
	volatylerTimer = 0;
	remoteTimer = 0;


	//preference setter
	preferences.begin("localData", false);
	stringOut = preferences.getString("mainOut", "Empty");
	sysCheck();
}

// The loop function is called in an endless loop
void loop() {

	currentTime = millis();

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
	//Serial.print(intervalTimer);
}

void snooze() {
	//Serial.print("SMOL TIME BBE");
}

//Feature A - CHECK SYS STATE
void sysCheck() {
	long waitingTimer = millis();
	bool dhtSens = false, pirSens = false, wifiCon = false, remoteCon = false;
	Serial.println("System is getting Ready");
	while (sysState == SYS_WAIT) {
		//SENSOR CHECK
		if (!isnan(humid) && !isnan(temp)) {
			dhtSens = true;
		}

		if (digitalRead(PIR_PIN) == HIGH) {
			pirSens = true;
		}

		//WIFI CHECK
		wifiCon = true;

		//REMOTE STORAGE
		remoteCon = true;

		if (dhtSens && pirSens && wifiCon && remoteCon) {
			sysState = SYS_READY;
		}

		if ((millis() - waitingTimer) >= 2000) {
			Serial.print(".");
			waitingTimer = millis();
		}

	}
	//Syt=t=stem is now ready
	Serial.println(".");
	Serial.println("System State has changed to SYS_READY");
	Serial.println("SYSTEM BEGIN");
	//Print out the locally stored value

	Serial.print("Local Store: ");
	dataOut();

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
		//sensorValOut();
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

	if ((millis() - pirTimer) >= 1000) {
		if (digitalRead(PIR_PIN) == HIGH) {
//				pirCount++;
//				Serial.print("Seconds: ");
//				Serial.println(pirCount);
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
	stringOut = "Running Time: " + String(millis());
	stringOut += " Humidity: " + String(humid) + " Temperature: "
			+ String(temp);
	stringOut += " LED state: " + String(ledCurrentState);
	stringOut += " PIR state: " + String(occupiedStatus);
	stringOut += " Interval Time: " + String(interval/1000) + "s";

}

void dataOut() {
	long timerCheck = interval;

	if(interval < 30000){
		timerCheck = 30000;
	}


	//Printing the debug String
	if ((millis() - stringTimer) >= 5000) {
		Serial.println(stringOut);
		stringTimer = millis();
	}

	//Setting volatile output
	if ((millis() - volatylerTimer) >= interval) {
			preferences.putString("mainOut", stringOut);
			volatylerTimer = millis();
		}

	//Setting remote output
	if ((millis() - remoteTimer) >= timerCheck) {
			//
			}
}
