#include <Arduino.h>
#include "Color.h"

/*
 * Pin Configuration - Color Sensor TCS3200
 */
const int s0 = 4;
const int s1 = 5;
const int s2 = 6;
const int s3 = 7;
const int colorSensorOut = 8;

/*
 * Color Constants
 */
const int totalColors = 7;

enum ColorType {
	NF, red, orange, yellow, green, blue, purple, pink
};

/*
 * Color First SetUp
 */
Color allColors[totalColors] =
		{ Color(49, 143, 99, ColorType::red), Color(25, 61, 64,
				ColorType::orange), Color(28, 37, 55, ColorType::yellow), Color(
				55, 48, 64, ColorType::green), Color(74, 54, 35,
				ColorType::blue), Color(38, 64, 35, ColorType::purple), Color(
				25, 90, 47, ColorType::pink) };


/*
 * Read the Input
 */
Color readColor() {
	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);
	int r = pulseIn(colorSensorOut, LOW);
	digitalWrite(s3, HIGH);
	int b = pulseIn(colorSensorOut, LOW);
	digitalWrite(s2, HIGH);
	int g = pulseIn(colorSensorOut, LOW);
	Color color(r, g, b,totalColors, allColors);
	return color;
}
