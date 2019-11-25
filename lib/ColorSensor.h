/*
 * ColorSensor.h
 * Class to manage the interactions with the censor TCS3200
 *
 *  Created on: 21 oct. 2019
 *      Author: mike
 */

#ifndef LIB_COLORSENSOR_H_
#define LIB_COLORSENSOR_H_

#include "Color.h"

enum FrequencyScaling {
	off, two, twenty, hundred
};

class ColorSensor {
public:
	ColorSensor(int s2, int s3, int out);
	void setFrequencyScaling(int s1, int s0, FrequencyScaling frequencyScaling);
	FrequencyScaling getFrequencyScaling();
	Color readColor();

private:
	int s0;
	int s1;
	FrequencyScaling frequencyScaling;
	int s2;
	int s3;
	int out;

};

#endif /* LIB_COLORSENSOR_H_ */
