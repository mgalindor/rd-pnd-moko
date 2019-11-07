#include <Arduino.h>
#include <Buzzer.h>
#include "Color.h"
#include "mokoSetUp.h"
#include "sounds.h"

/*
 * Read the Input
 */
Color readColor() {
	digitalWrite(col_s2, LOW);
	digitalWrite(col_s3, LOW);
	// S2 = 0 , S3 =0
	int r = pulseIn(col_out, LOW);
	digitalWrite(col_s3, HIGH);
	// S2 = 0 , S3 =1
	int b = pulseIn(col_out, LOW);
	digitalWrite(col_s2, HIGH);
	// S2 = 1 , S3 =1
	int g = pulseIn(col_out, LOW);
	int totalColors = sizeof(allColors) / sizeof(allColors[0]);
	Color color(r, g, b, totalColors, allColors);
	return color;
}

void playSound(Buzzer *buzzer, Note notes[], int numberOfNotes) {
	for (int i = 0; i < numberOfNotes; i++) {
		Note n = notes[i];
		buzzer->sound(n.note, n.duration);
	}
}

void playSoundStart(Buzzer *buzzer) {
	int numberOfNotes = sizeof(start_song) / sizeof(start_song[0]);
	playSound(buzzer, start_song, numberOfNotes);
}

void playSoundEnd(Buzzer *buzzer) {
	int numberOfNotes = sizeof(end_song) / sizeof(end_song[0]);
	playSound(buzzer, end_song, numberOfNotes);
}

void playSoundWorking(Buzzer *buzzer) {
	int numberOfNotes = sizeof(working_song) / sizeof(working_song[0]);
	playSound(buzzer, working_song, numberOfNotes);
}

void playSoundConfused(Buzzer *buzzer) {
	int numberOfNotes = sizeof(confused_song) / sizeof(confused_song[0]);
	playSound(buzzer, confused_song, numberOfNotes);
}

void playSoundSleeping(Buzzer *buzzer) {
	int numberOfNotes = sizeof(confused_sleeping)
			/ sizeof(confused_sleeping[0]);
	playSound(buzzer, confused_sleeping, numberOfNotes);
}

void moveForward(CheapStepper *mRight, CheapStepper *mLeft) {
	Serial.println("Avanzo");
	for(int i = 0; i<STEPS;i++) {
		mRight->stepCCW();
		mLeft->stepCW();
	}
	delay(3000);
}

void turnRight(CheapStepper *mRight, CheapStepper *mLeft) {
	Serial.println("Giro Drecha");
	mRight->moveCCW(STEPS);
	moveForward(mRight, mLeft);
}

void turnLeft(CheapStepper *mRight, CheapStepper *mLeft) {
	Serial.println("Giro Izquierda");
	mLeft->moveCW(STEPS);
	moveForward(mRight, mLeft);
}

