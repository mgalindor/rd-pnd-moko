#include "../lib/Moko.h"
#include "../lib/mokoSetUp.h"

void readColorLoop(Moko *moko, ColorType colortype) {

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
