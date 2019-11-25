/*
 * ColorSensor.cpp
 *
 *  Created on: 21 oct. 2019
 *      Author: mike
 */

#include "ColorSensor.h"
#include <Arduino.h>

ColorSensor::ColorSensor(int s2, int s3, int out) {
	this->s2 = s2;
	this->s3 = s3;
	this->out = out;

	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);
	pinMode(out, INPUT);

	this->s0 = 0;
	this->s1 = 0;
	this->frequencyScaling = FrequencyScaling::off;
}

void ColorSensor::setFrequencyScaling(int s1, int s0,
		FrequencyScaling frequencyScaling) {
	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	switch (frequencyScaling) {
	case off:
		digitalWrite(s0, LOW);
		digitalWrite(s1, LOW);
		break;
	case two:
		digitalWrite(s0, LOW);
		digitalWrite(s1, HIGH);
		break;
	case twenty:
		digitalWrite(s0, HIGH);
		digitalWrite(s1, LOW);
		break;
	case hundred:
		digitalWrite(s0, HIGH);
		digitalWrite(s1, HIGH);
		break;
	}

}

FrequencyScaling ColorSensor::getFrequencyScaling() {
	return this->frequencyScaling;
}

Color ColorSensor::readColor() {
	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);
	// S2 = 0 , S3 =0
	int r = pulseIn(out, LOW);
	digitalWrite(s3, HIGH);
	// S2 = 0 , S3 =1
	int b = pulseIn(out, LOW);
	digitalWrite(s2, HIGH);
	// S2 = 1 , S3 =1
	int g = pulseIn(out, LOW);
	Color color(r, g, b);
	return color;
}

