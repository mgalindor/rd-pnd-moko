#include <Arduino.h>
#include "Color.h"

const int s0 = 4;
const int s1 = 5;
const int s2 = 6;
const int s3 = 7;
const int out = 8;
const int totalColors = 7;

enum ColorType {
	NF, red, orange, yellow, green, blue, purple, pink
};

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink" };

Color allColors[totalColors] =
		{ Color(49, 143, 99, ColorType::red), Color(25, 61, 64,
				ColorType::orange), Color(28, 37, 55, ColorType::yellow), Color(
				55, 48, 64, ColorType::green), Color(74, 54, 35,
				ColorType::blue), Color(38, 64, 35, ColorType::purple), Color(
				25, 90, 47, ColorType::pink) };

void setup() {
	Serial.begin(9600);
	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);
	pinMode(out, INPUT);
	digitalWrite(s0, HIGH);
	digitalWrite(s1, LOW);
}

Color readColor() {
	int r = 0;
	int g = 0;
	int b = 0;

	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);
	r = pulseIn(out, LOW);
	digitalWrite(s3, HIGH);
	b = pulseIn(out, LOW);
	digitalWrite(s2, HIGH);
	g = pulseIn(out, LOW);
	Color color(r, g, b,totalColors, allColors);
	return color;
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

