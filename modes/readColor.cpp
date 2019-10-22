#include <Arduino.h>

#include "../lib/Moko.h"
#include "../lib/Color.h"
#include "../lib/ColorSensor.h"
#include "../lib/mokoSetUp.h"

String results[] = { "Not Found", "red", "orange", "yellow", "green", "blue",
		"purple", "pink", "brown" };

bool readColorLoop(Moko *moko, ColorSensor *colorSensor, bool started) {

	bool inProcess = started;

	Color rgb = colorSensor->readColor();
	int totalColors = sizeof(allColors) / sizeof(allColors[0]);
	Color color(rgb.getR(), rgb.getG(), rgb.getB(), totalColors, allColors);

	int type = color.getColorType();
	String typeString = results[type];
	Serial.println(
			" Color:[" + String(typeString) + "] Type:[" + String(type) + "]");

	if (!inProcess && type != ColorType::green) {
		moko->playSoundSleeping();
	} else if (!inProcess && type == ColorType::green) {
		inProcess = true;
		moko->playSoundStart();
		moko->moveForward();
	} else if (inProcess) {
		switch (type) {
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
			inProcess = false;
			break;
		default:
			moko->playSoundConfused();
			break;
		}
	}
	return inProcess;
}
