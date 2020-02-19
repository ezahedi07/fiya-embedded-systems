#include "Button.h"
#include "dhtesp.h"
#include <Preferences.h>
#define DHTPIN 4
#define DHTTYPE DHTesp::DHT11

enum ledState{
	LED_GREEN,
	LED_AMBER,
	LED_RED

};

enum systemState{
	SYS_READY,
	SYS_WAIT
};

enum occupiedState{
	ROOM_OCCUPIED,
	ROOM_VACANT
};

ButtonState btnCurrent;

//Pin numbers
const int SWITCH_PIN = 19;
const int POTIN_PIN = 32;
const int PIR_PIN= 14;

//Global counters
int count = 0;
int potCount = 0;
int pirCount = 0;

//Set button
Button* button = NULL;

//set various system states
ledState ledCurrentState;
systemState sysState = SYS_WAIT;
occupiedState occupiedStatus = ROOM_VACANT;

//LED Settings
int rgbLedArray[3] = {1,2,3};
const int ledR = 23, ledG = 21, ledB = 22;
int R,  G,  B;

//global timer - poor method, look for other implimentations
long currentTime, dhtTimer, pirTimer, pirLongTimer, stringTimer;

//DHT11 SENSOR Vars
float humid;
float temp;
DHTesp dht;

//Global string out
String stringOut;

//Preference setup
Preferences preferences;

void printOut(){
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
	pinMode(PIR_PIN,INPUT);


	//Attach the button to the switch pin
	button = new Button(SWITCH_PIN);

	//Test RGB LED
	for(int i=0; i < 3; i++) {
	  ledcWrite(rgbLedArray[i], 255);
	  delay(1000);
	  ledcWrite(rgbLedArray[i], 0);
	 }


	//PIR interrupt
	attachInterrupt(digitalPinToInterrupt(PIR_PIN), printOut, RISING);

	//Begin Serial listener
	Serial.begin(9600);


	//Initialise the timer variables
	dhtTimer = 0;
	pirTimer = 0;
	pirLongTimer = 0;
	stringTimer = -5100;

	//preference setter
	preferences.begin("localData", false);
	stringOut = preferences.getString("mainOut", "Empty");

}




// The loop function is called in an endless loop
void loop() {

	currentTime = millis();
	if(sysState == SYS_WAIT){
		sysCheck();
	}else if (sysState == SYS_READY){

		//Feature SET B
		sensorRead();
		ledSwitch();

		//Feature Set D
		pirSensorRead();

		//String Creator
		finalStringOut();


		//Feature Set E
		localStringStorage();



		//Feature SET C
		debugStringOut();



	}

	ButtonState btnRead = button->checkState();
	potCount = analogRead(POTIN_PIN);
	if(btnRead != btnCurrent){
				btnCurrent = btnRead;
				switch (btnCurrent) {
				case ButtonState::ON:
					count++;
					Serial.print("Btn Count (");
					Serial.print(count);
					Serial.print(")");
					Serial.print(" Pot Val (");
					Serial.print(potCount);
					Serial.println(")");
					break;
				case ButtonState::OFF:
					break;
				}
	}
	if(count == 3){
			count = 0;
		}
}


//Feature A - CHECK SYS STATE
void sysCheck(){
	//Check if the connected components are running and connected
	//if No then wait an return SYS_WAIT;

	//if yes then return SYS_READY

	delay(4000);
	Serial.println("Simulating Delay - Remove This");
	sysState = SYS_READY;
	Serial.print("FIRST: ");
	debugStringOut();
}


void sensorRead(){

// read the value of the sensors and set them to variables
	if(( millis() - dhtTimer ) >= 2000){
		TempAndHumidity newValues = dht.getTempAndHumidity();
		humid = newValues.humidity;
		temp = newValues.temperature;
		dhtTimer = millis();
		if (isnan(humid) || isnan(temp)){
			    Serial.println(F("Failed to read from DHTesp sensor!"));
			    return;
			  }
		//sensorValOut();
	}



}

void ledSwitch(){
//switch the colour of the LED depending on variables
	if((temp >= 18 && temp <= 23) && (humid >= 35 && humid <= 60)){
		//Set colour Green
		R = 0;
		G = 255;
		B = 0;
		ledCurrentState = LED_GREEN;
	}else if((temp >= 16 && temp <= 27) && (humid >= 25 && humid <= 75)){
		//Set Colour Amber
		R = 255;
		G = 80;
		B = 0;
		ledCurrentState = LED_AMBER;
	}else{
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


//void sensorValOut(){
////Print the value of the sensors as a string;
//	Serial.print("Temp: ");
//	Serial.print(temp);
//	Serial.print("  Humid: ");
//	Serial.println(humid);
//}



void pirSensorRead(){

	if((millis() - pirTimer) >= 1000){
			if(digitalRead(PIR_PIN) == HIGH){
//				pirCount++;
//				Serial.print("Seconds: ");
//				Serial.println(pirCount);
				occupiedStatus = ROOM_OCCUPIED;
				pirLongTimer = millis();
			}else if(digitalRead(PIR_PIN == LOW) && occupiedStatus != ROOM_VACANT){
				if((millis() - pirLongTimer )>60000){
					occupiedStatus = ROOM_VACANT;
					Serial.println("Room VACANT");
				}


			}
			pirTimer = millis();
		}

}

void localStringStorage(){

}

void finalStringOut(){

	/* Humidity
	 * Temp
	 * LED state
	 * PIR state
	 * Output interval
	 * Alert status + snooze
	 *
	 * */
	stringOut = "Humidity: " + String(humid) + " Temperature: " + String(temp);
	stringOut += "/n LED state: " + String(ledCurrentState);
	stringOut += "/n PIR state: " + String(occupiedStatus);

}

void debugStringOut(){
	if((millis() - stringTimer) >= 5000){

		Serial.println(stringOut);
		preferences.putString("mainOut", stringOut);
		stringTimer = millis();
	}
}
