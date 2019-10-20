#include <Arduino.h>
#include <CheapStepper.h>
#include <Buzzer.h>
#include "mokoActions.h"

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink", "brown" };

bool inProcess = false;
Buzzer *buzzer = NULL;
CheapStepper *mRight = NULL;
CheapStepper *mLeft = NULL;

void setup() {
	Serial.begin(9600);

	// Color Sensor TCS3200
	pinMode(col_s2, OUTPUT);
	pinMode(col_s3, OUTPUT);
	pinMode(col_out, INPUT);
	//  Setting Color Sensor TCS3200 frequency-scaling to 20% Setting up manually
	//pinMode(col_s0, OUTPUT);
	//pinMode(col_s1, OUTPUT);
	//digitalWrite(col_s0, HIGH);
	//digitalWrite(col_s1, LOW);

	// ULN2003/28BYJ-48 , CheapStepper configures the pinMode
	mRight = new CheapStepper(mR_in1, mR_in2, mR_in3, mR_in4);
	mLeft = new CheapStepper(mL_in1, mL_in2, mL_in3, mL_in4);

	// Buzzer
	buzzer = new Buzzer(bzz_in);
}

void loop() {
	Color color = readColor();

	int type = color.getColorType();
	String typeString = results[type];
	Serial.println(
			" Color:[" + String(typeString) + "] Type:[" + String(type) + "]");

	if (!inProcess && type != ColorType::green) {
		playSoundSleeping(buzzer);
	} else if (!inProcess && type == ColorType::green) {
		playSoundStart(buzzer);
		inProcess = true;
		moveForward(mRight, mLeft);
	} else if (inProcess) {
		switch (type) {
		case ColorType::blue:
			playSoundWorking(buzzer);
			moveForward(mRight, mLeft);
			break;
		case ColorType::orange:
			playSoundWorking(buzzer);
			turnLeft(mRight, mLeft);
			break;
		case ColorType::purple:
			playSoundWorking(buzzer);
			turnRight(mRight, mLeft);
			break;
		case ColorType::red:
			playSoundEnd(buzzer);
			inProcess = false;
			break;
		default:
			playSoundConfused(buzzer);
			break;
		}
	}

	delay(5000);
}

