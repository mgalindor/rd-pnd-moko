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

void excecColor(Moko *moko, ColorType colortype) {

	switch (colortype) {
	case ColorType::green:
		moko->playSoundStart();
		moko->moveForward();
		break;
	case ColorType::blue:
		moko->playSoundWorking();
		moko->moveForward();
		break;
	case ColorType::orange:
		moko->playSoundWorking();
		moko->turnLeft();
		break;
	case ColorType::purple:
		moko->playSoundWorking();
		moko->turnRight();
		break;
	case ColorType::red:
		moko->playSoundEnd();
		break;
	default:
		moko->playSoundConfused();
		break;
	}
}

void loop() {
	inProcess = excecColor(moko,ColorType::green);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::orange);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::purple);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::blue);
	inProcess = excecColor(moko,ColorType::red);
	delay(5000);
}
