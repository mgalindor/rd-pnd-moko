/*
 * Moko.h
 *
 *
 *  Created on: 20 oct. 2019
 *      Author: Miguel Galindo
 */

#ifndef LIB_MOKO_H_
#define LIB_MOKO_H_

#include "Note.h"

#include <Buzzer.h>
#include <CheapStepper.h>

class Moko {
public:
	Moko(Buzzer *buzzer);
	Moko(CheapStepper *mRight, CheapStepper *mLeft);
	Moko(CheapStepper *mRight, CheapStepper *mLeft, Buzzer *buzzer);
	void playSound(Note notes[], int numberOfNotes);
	void playSoundStart();
	void playSoundEnd();
	void playSoundWorking();
	void playSoundConfused();
	void playSoundSleeping();
	void moveForward();
	void moveBackward();
	void moveForward(int numSteps);
	void moveBackward(int numSteps);
	void turnRight();
	void turnLeft();
	void turnRight(int numSteps);
	void turnLeft(int numSteps);
	void stop();
	void setSteps(int steps);
	static Note START_SONG[];
	static Note END_SONG[];
	static Note WORKING_SONG[];
	static Note CONFUSED_SONG[];
	static Note SLEEPING_SONG[];

private:
	CheapStepper *mRight;
	CheapStepper *mLeft;
	Buzzer *buzzer;
	int steps;
};

#endif /* LIB_MOKO_H_ */
