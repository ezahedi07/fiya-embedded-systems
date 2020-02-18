#include "Button.h"
#include "dhtesp.h"
#define DHTPIN 4
#define DHTTYPE DHTesp::DHT11

enum ledState{
	LED_GREEN,
	LED_RED,
	LED_AMBER
};
enum systemState{
	SYS_READY,
	SYS_WAIT
};

ButtonState btnCurrent;

const int SWITCH_PIN = 19;
const int POTIN_PIN = 32;
const int PIR_PIN= 16;
int count = 0;
int potCount = 0;
Button* button = NULL;
ledState ledCurrentState;
systemState sysState = SYS_WAIT;

//LED Settings
int rgbLedArray[3] = {1,2,3};
const int ledR = 23, ledG = 21, ledB = 22;
int R,  G,  B;
long currentTime, oldTime;

//
float humid;
float temp;
//
DHTesp dht;
void printOut(){
		Serial.println("PIR HIGH");
	}

void setup() {

	dht.setup(DHTPIN, DHTesp::DHT11);

	//Attach the LED pins to a channel
	ledcAttachPin(ledR, 1);
	ledcAttachPin(ledG, 2);
	ledcAttachPin(ledB, 3);

	//Attach the Channel with a 12khz PWM and 8-bit resolution
	ledcSetup(1, 12000, 8);
	ledcSetup(2, 12000, 8);
	ledcSetup(3, 12000, 8);

	pinMode(PIR_PIN,INPUT);

	//dht.begin();

	for(int i=0; i < 3; i++) {
	  // ledcWrite(channel, dutycycle)
	  // For 8-bit resolution duty cycle is 0 - 255
	  ledcWrite(rgbLedArray[i], 255);  // test high output of all leds in sequence
	  delay(1000);
	  ledcWrite(rgbLedArray[i], 0);
	 }



	attachInterrupt(digitalPinToInterrupt(PIR_PIN), printOut, RISING);

	pinMode(PIR_PIN, INPUT);
	Serial.begin(9600);
	button = new Button(SWITCH_PIN);

	currentTime = millis();
	oldTime = 0;
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

		//Feature SET C


//		if(digitalRead(SWITCH_PIN) == LOW){
//			Serial.println("PIR LOW");
//		}else if(digitalRead(SWITCH_PIN) == HIGH){
//			Serial.println("PIR HIGH");
//		}


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

	delay(3000);
	Serial.println("Simulating Delay - Remove This");
	sysState = SYS_READY;
}


void sensorRead(){

// read the value of the sensors and set them to variables
	//delay(2000);
	if(( millis() - oldTime ) > 2000){
		TempAndHumidity newValues = dht.getTempAndHumidity();
		humid = newValues.humidity;
		temp = newValues.temperature;
		oldTime = millis();
		Serial.println(oldTime);
		Serial.println( millis());
		if (isnan(humid) || isnan(temp)){
			    Serial.println(F("Failed to read from DHTesp sensor!"));
			    return;
			  }
		sensorValOut();
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

	//int lastTemp = testTemp;
	//int lastHum = testHum;

	ledcWrite(1, R);
	ledcWrite(2, G);
	ledcWrite(3, B);
}


void sensorValOut(){
//Print the value of the sensors as a string;
	Serial.print("Temp: ");
	Serial.print(temp);
	Serial.print("  Humid: ");
	Serial.println(humid);
}


