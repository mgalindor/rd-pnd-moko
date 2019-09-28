#include <Arduino.h>
#include "Color.h"
#include "moko.h"

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink" };

void setup() {
	Serial.begin(9600);

	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);
	pinMode(colorSensorOut, INPUT);

	// Setting Color Sensor TCS3200 frequency-scaling to 20%
	digitalWrite(s0, HIGH);
	digitalWrite(s1, LOW);
}

void loop() {
	Color color = readColor();

	int type = color.getColorType();
	String typeString = results[type];

	Serial.print(" Color :");
	Serial.print(typeString);
	Serial.print(" Type:");
	Serial.print(type, DEC);
	Serial.println("");

	delay(1000);
}

