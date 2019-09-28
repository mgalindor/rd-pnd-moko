/*
 * Color.cpp
 *
 *  Created on: 7 sep. 2019
 *      Author: Miguel Galindo
 */
#include "Color.h"
#include <math.h>

Color::Color(int redIn, int greenIn, int blueIn, int totalColors,
		Color allColors[]) {
	r = redIn;
	g = greenIn;
	b = blueIn;
	colorType = calculateColorType(totalColors, allColors);
}

Color::Color(int red, int green, int blue, int colorTypeIn) {
	r = red;
	g = green;
	b = blue;
	colorType = colorTypeIn;
}

int Color::getB() {
	return b;
}

int Color::getG() {
	return g;
}

int Color::getR() {
	return r;
}

int Color::getColorType() {
	return colorType;
}

double Color::getDistance(Color color) {
	double powAxis = pow(color.r - this->r, 2) + pow(color.g - this->g, 2)
			+ pow(color.b - this->b, 2);
	return sqrt(powAxis);
}

int Color::calculateColorType(int totalColors, Color allColors[]) {
	int resutlColorType = 0;
	double minorDistance = 0;
	for (int i = 0; i < totalColors; i++) {
		Color c = allColors[i];
		double distance = getDistance(c);
		if (distance == 0) {
			resutlColorType = c.colorType;
			break;
		} else if (minorDistance == 0 || minorDistance > distance) {
			minorDistance = distance;
			resutlColorType = c.colorType;
		}
	}
	return resutlColorType;
}
