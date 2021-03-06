#include "Moko.h"
#include "Note.h"

#include <Arduino.h>
#include <Buzzer.h>
#include <CheapStepper.h>

Note Moko::START_SONG[] = { Note(NOTE_DS7, QUARTER), Note(NOTE_FS7,
WHITE), Note(NOTE_DS7, QUARTER), Note(NOTE_FS7, WHITE), Note(NOTE_DS7,
QUARTER), Note(NOTE_B7, WHITE_DOTTED) };

Note Moko::END_SONG[] = { Note(NOTE_B7, QUARTER), Note(NOTE_DS7, QUARTER), Note(
NOTE_FS7, WHITE), Note(0, EIGHT), Note(NOTE_FS7, EIGHT), Note(0, EIGHT), Note(
NOTE_FS7, QUARTER), Note(NOTE_B7, WHITE_DOTTED) };

Note Moko::WORKING_SONG[] = { Note(NOTE_DS7, HALF), Note(0, QUARTER), Note(
NOTE_FS7, HALF), Note(0, EIGHT), Note(NOTE_DS7, HALF), Note(0, QUARTER), Note(
NOTE_FS7, HALF) };

Note Moko::CONFUSED_SONG[] = { Note(NOTE_DS8, HALF), Note(0, EIGHT), Note(
NOTE_GS8, HALF) };

Note Moko::SLEEPING_SONG[] = { Note(NOTE_DS7, HALF), Note(0, EIGHT), Note(
NOTE_DS7, HALF), Note(NOTE_FS7, WHITE_DOTTED), Note(0, WHITE), Note(
NOTE_DS7, HALF), Note(0, EIGHT), Note(NOTE_DS7, HALF), Note(NOTE_FS7,
WHITE_DOTTED) };

Moko::Moko(CheapStepper *mRight, CheapStepper *mLeft, Buzzer *buzzer) {
	this->mRight = mRight;
	this->mLeft = mLeft;
	this->buzzer = buzzer;
	this->steps = 2048;

	this->mRight->setTotalSteps(4096);
	this->mRight->setRpm(15);

	this->mLeft->setTotalSteps(4096);
	this->mLeft->setRpm(15);
}

void Moko::playSound(Note notes[], int numberOfNotes) {
	for (int i = 0; i < numberOfNotes; i++) {
		Note n = notes[i];
		buzzer->sound(n.frequency, n.duration);
	}
}

void Moko::playSoundStart() {
	int numberOfNotes = sizeof(START_SONG) / sizeof(START_SONG[0]);
	playSound(START_SONG, numberOfNotes);
}

void Moko::playSoundEnd() {
	int numberOfNotes = sizeof(END_SONG) / sizeof(END_SONG[0]);
	playSound(END_SONG, numberOfNotes);
}

void Moko::playSoundWorking() {
	int numberOfNotes = sizeof(WORKING_SONG) / sizeof(WORKING_SONG[0]);
	playSound(WORKING_SONG, numberOfNotes);
}

void Moko::playSoundConfused() {
	int numberOfNotes = sizeof(CONFUSED_SONG) / sizeof(CONFUSED_SONG[0]);
	playSound(CONFUSED_SONG, numberOfNotes);
}

void Moko::playSoundSleeping() {
	int numberOfNotes = sizeof(SLEEPING_SONG) / sizeof(SLEEPING_SONG[0]);
	playSound(SLEEPING_SONG, numberOfNotes);
}

void Moko::moveForward() {
	moveForward(steps);
}

void Moko::moveBackward() {
	moveBackward(steps);
}

void Moko::moveForward(int numSteps) {
	for (int i = 0; i < numSteps; i++) {
		mRight->stepCCW();
		mLeft->stepCW();
	}
}

void Moko::moveBackward(int numSteps) {
	for (int i = 0; i < numSteps; i++) {
		mRight->stepCW();
		mLeft->stepCCW();
	}
}

void Moko::turnRight() {
	turnRight(steps);
}

void Moko::turnLeft() {
	turnLeft(steps);
}

void Moko::turnRight(int numSteps) {
	for (int i = 0; i < numSteps; i++) {
		mRight->stepCW();
		mLeft->stepCW();
	}
}

void Moko::turnLeft(int numSteps) {
	for (int i = 0; i < numSteps; i++) {
		mLeft->stepCCW();
		mRight->stepCCW();
	}
}

void Moko::setSteps(int steps) {
	this->steps = steps;
}

