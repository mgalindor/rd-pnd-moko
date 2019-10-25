#include <Arduino.h>
#include <CheapStepper.h>
#include <Buzzer.h>

#include "lib/ColorSensor.h"
#include "lib/mokoSetUp.h"
#include "modes/readColor.h"

bool inProcess = false;
Buzzer *buzzer = NULL;
CheapStepper *mRight = NULL;
CheapStepper *mLeft = NULL;
ColorSensor *colorSensor = NULL;
Moko *moko = NULL;

void setup() {
	Serial.begin(9600);

	// Color Sensor TCS3200
	colorSensor = new ColorSensor(col_s2, col_s3, col_out);

	// ULN2003/28BYJ-48 , CheapStepper configures the pinMode
	mRight = new CheapStepper(mR_in1, mR_in2, mR_in3, mR_in4);
	mLeft = new CheapStepper(mL_in1, mL_in2, mL_in3, mL_in4);

	// Buzzer
	buzzer = new Buzzer(bzz_in);
	moko = new Moko(mRight, mLeft, buzzer);
}

void loop() {
	inProcess = readColorLoop(moko, colorSensor, inProcess);
	delay(5000);
}

