#include "Button.h"
#include "dhtesp.h"
#include <Preferences.h>
#include <HTTPClient.h>
#include "RESTFUL.h"

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

//WiFi Pass and SSID
const char* PASS = "cjry3646";
const char* SSID = "JcPhone";

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
long currentTime, dhtTimer, pirTimer, pirLongTimer, pirSysCheck, stringTimer, volatylerTimer,
		remoteTimer, btnTimer, wifiRepeateTimer;

//DHT11 SENSOR Vars
float humid;
float temp;
DHTesp dht;

//Global string out
String stringOut;

//Global BOOL
boolean pirReady = false;
boolean wifiReady = false;

//Preference setup
Preferences preferences;

WiFiServer server;

RESTFUL rest;

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



	//Begin Serial listener
	Serial.begin(115200);

	//Initialise the timer variables
	dhtTimer = 0;
	pirTimer = 0;
	pirLongTimer = 0;
	stringTimer = -5100;
	volatylerTimer = 0;
	remoteTimer = 0;
	pirSysCheck = 0;

	//preference setter
	preferences.begin("localData", false);
	stringOut = preferences.getString("mainOut", "Empty");

	Serial.print("Connecting to ");
	Serial.println(SSID);
	WiFi.begin(SSID, PASS);

	sysCheck();
	server.begin(1337);
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

	//WifiCheck

	wifiReadyCheck();


	//wifi Server Check -- Probably change or remove this
	wifiServerCheck();







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

void wifiReadyCheck(){
	if(wifiReady == false){
	if((millis() - wifiRepeateTimer) >= 5000){
		if(WiFi.status() == WL_CONNECTED){
				wifiReady = true;
				Serial.print("Connected as : ");
				Serial.println(WiFi.localIP());
			}else{
				Serial.print("Not Connected");
				//WiFi.begin(SSID, PASS);
				WiFi.reconnect();
			}
		wifiRepeateTimer = millis();
	}
	}else if (WiFi.status() == WL_DISCONNECTED ){
		wifiReady = false;
	}
}

void wifiServerCheck(){
	WiFiClient client = server.available();
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
	//Serial.print("SMOL TIME BBE");
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

		/*
		 * Change this section
		 * the system can begin running in a staggered form where components come online while other
		 * components become ready.
		 * We should also have the 60 second wait period for the PIR sensor before we deem it to be "on"
		 * DHT functionality is currently fine
		 * System can be started without wifi connection as long as it is announced to the user
		 * Other test could be done on things such as buttons, although the use an need is questionable.
		 */

		//Start the 60 seconds PIR timer
		pirSysCheck = millis();


		//True if wifi is connected else true with a new timer
		if (WiFi.status() == WL_CONNECTED && wifiEscape != true) {
			wifiEscape= true;
		}else{
			wifiRepeateTimer = millis();
			wifiEscape= true;
			Serial.println("The system will run without wifi." );
		}


		//REMOTE STORAGE
		remoteCon = true;

		if (dhtSens  && wifiEscape && remoteCon) {
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
	Serial.println(".");
	Serial.println("System State has changed to SYS_READY");

	if(wifiReady == true){
		Serial.print("Connected as : ");
		Serial.println(WiFi.localIP());
	}

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


	if(pirReady == true){
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
	}else{
		if((millis() - pirSysCheck) >= 60000){
			pirReady = true;
		}
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
	if(pirReady == false){
		stringOut += " PIR state: Warming";
	}else{
		stringOut += " PIR state: " + String(occupiedStatus);
	}
	stringOut += " Interval Time: " + String(interval / 1000) + "s";

	if(wifiReady == false){
		stringOut += " WiFi is currently not connected";
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
	if ((millis() - volatylerTimer) >= 5000) {
		preferences.putString("mainOut", stringOut);
		volatylerTimer = millis();
	}

	//Setting remote output
	if ((millis() - remoteTimer) >= timerCheck) {
		//
	}
}




