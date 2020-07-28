#include <Arduino.h>
#include <CheapStepper.h>
#include <Buzzer.h>

#include "lib/Color.h"
#include "lib/ColorSensor.h"
#include "lib/Moko.h"
#include "lib/mokoSetUp.h"



bool inProcess = false;
Buzzer *buzzer = NULL;
CheapStepper *mRight = NULL;
CheapStepper *mLeft = NULL;
ColorSensor *colorSensor = NULL;
Moko *moko = NULL;

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink", "brown" };

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


bool readColorLoop(Moko *moko, ColorSensor *colorSensor, bool started) {

	bool process = started;

	Color rgb = colorSensor->readColor();
	int totalColors = sizeof(allColors) / sizeof(allColors[0]);
	Color color(rgb.getR(), rgb.getG(), rgb.getB(), totalColors, allColors);

	int type = color.getColorType();
	String typeString = results[type];
	Serial.println("R:"+String(color.getR())+" G:"+String(color.getG())+" B:"+String(color.getB()));
	Serial.println("Color:[" + String(typeString) + "] Type:[" + String(type) + "]");

	if (!process && type != ColorType::green) {
		moko->playSoundSleeping();
	} else if (!process && type == ColorType::green) {
		process = true;
		moko->playSoundStart();
		moko->moveForward();
	} else if (process) {
		switch (type) {
		case ColorType::blue:
			moko->playSoundWorking();
			moko->moveForward();
			break;
		case ColorType::orange:
			moko->playSoundWorking();
			moko->turnLeft();
			moko->moveForward();
			break;
		case ColorType::purple:
			moko->playSoundWorking();
			moko->turnRight();
			moko->moveForward();
			break;
		case ColorType::red:
			moko->playSoundEnd();
			process = false;
			break;
		default:
			moko->playSoundConfused();
			break;
		}
	}
	return process;
}


void loop() {
	inProcess = readColorLoop(moko, colorSensor, inProcess);
	delay(5000);
}

