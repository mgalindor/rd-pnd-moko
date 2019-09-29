#include <Arduino.h>
#include <CheapStepper.h>
#include <Buzzer.h>
#include "Color.h"
#include "moko.h"

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink" };

bool inProcess = false;
Buzzer* buzzer = NULL;
CheapStepper* mRight = NULL;
CheapStepper* mLeft = NULL;


void setup() {
	Serial.begin(9600);

	// Color Sensor TCS3200
	pinMode(col_s2, OUTPUT);
	pinMode(col_s3, OUTPUT);
	pinMode(col_out, INPUT);
	//  Setting Color Sensor TCS3200 frequency-scaling to 20% Setting up manually
	pinMode(col_s0, OUTPUT);
	pinMode(col_s1, OUTPUT);
	digitalWrite(col_s0, HIGH);
	digitalWrite(col_s1, LOW);

	// ULN2003/28BYJ-48 , CheapStepper configures the pinMode
	//CheapStepper mRight (m1_in1,m1_in2,m1_in3,m1_in4);
	//CheapStepper mLeft (m2_in1,m2_in2,m2_in3,m2_in4);

	// Buzzer
	buzzer = new Buzzer(bzz_in);
}

void loop() {
	Color color = readColor();
	int type = color.getColorType();
	String typeString = results[type];

	int size = sizeof(allColors)/sizeof(allColors[0]);

	Serial.println(
			" Color:[" + String(typeString) + "] Type:[" + String(type) + "]");
	if (!inProcess && type != ColorType::green ) {
		playSoundSleeping(buzzer);
	}
	else if (!inProcess && type == ColorType::green) {
		playSoundStart(buzzer);
		inProcess = true;
		moveForward();
	}
	else if(inProcess){
		switch (type) {
			case ColorType::blue:
				playSoundWorking(buzzer);
				moveForward();
				break;
			case ColorType::orange:
				playSoundWorking(buzzer);
				turnLeft();
				break;
			case ColorType::purple:
				playSoundWorking(buzzer);
				turnRight();
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

