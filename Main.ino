#include "Button.h"
enum ledState{
	LED_GREEN,
	LED_RED,
	LED_AMBER
};


ButtonState btnCurrent;
const int LED_PIN = 13;
const int R = 18, G = 19, B = 21;
const int SWITCH_PIN = 14;
const int POTIN_PIN = 32;
int count = 0;
int potCount = 0;
Button* button = NULL;
ledState ledCurrentState = LED_GREEN;




void setup() {

	pinMode(LED_PIN, OUTPUT);
	pinMode(R, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(B, OUTPUT);
	Serial.begin(9600);
	button = new Button(SWITCH_PIN);
}




// The loop function is called in an endless loop
void loop() {
	ButtonState btnRead = button->checkState();
	potCount = analogRead(POTIN_PIN);
	if(btnRead != btnCurrent){

				btnCurrent = btnRead;
				switch (btnCurrent) {
				case ButtonState::ON:
					count++;
					Serial.print("Class Btn Pressed (");
					Serial.print(count);
					Serial.print(")");
					Serial.print("  Pot val (");
					Serial.print(potCount);
					Serial.println(")");
					break;
				case ButtonState::OFF:
					break;
				}

	}
	ledStateSwitch();
	if(count == 3){
			count = 0;
		}

}


void ledStateSwitch(){
	if(count == 1){
		ledCurrentState = LED_GREEN;
		digitalWrite(R, LOW);
		digitalWrite(G, HIGH);
		digitalWrite(B, LOW);
	}
	else if(count == 2){
		ledCurrentState = LED_AMBER;
		digitalWrite(R, LOW);
		digitalWrite(G, LOW);
		digitalWrite(B, HIGH);
	}
	else if(count == 3){
		ledCurrentState = LED_RED;
		digitalWrite(R, HIGH);
		digitalWrite(G, LOW);
		digitalWrite(B, LOW);
		}
}
