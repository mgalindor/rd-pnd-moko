#include <Arduino.h>
#include <Buzzer.h>
#include "Color.h"
#include "sounds.h"

#define STEPS 2048

/*
 * PIN Configuration - Color Sensor TCS3200
 */
const int col_s0 = 4; // Configured Externally
const int col_s1 = 5; // Configured Externally
const int col_s2 = 6;
const int col_s3 = 7;
const int col_out = 8;

/*
 * PIN Configuration - ULN2003/28BYJ-48
 */
const int m1_in1= 5;
const int m1_in2= 6;
const int m1_in3= 7;
const int m1_in4= 8;

const int m2_in1= 9;
const int m2_in2= 10;
const int m2_in3= 11;
const int m2_in4= 12;

/*
 * PIN Configuration - Buzzer
 */
const int bzz_in = 13;

enum ColorType {
	NF, red, orange, yellow, green, blue, purple, pink
};

/*
 * Color First SetUp
 */
Color allColors[] =
		{ Color(49, 143, 99, ColorType::red), Color(25, 61, 64,
				ColorType::orange), Color(28, 37, 55, ColorType::yellow), Color(
				55, 48, 64, ColorType::green), Color(74, 54, 35,
				ColorType::blue), Color(38, 64, 35, ColorType::purple), Color(
				25, 90, 47, ColorType::pink) };

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
	int totalColors =  sizeof(allColors)/sizeof(allColors[0]);
	Color color(r, g, b,totalColors, allColors);
	return color;
}

void playSound(Buzzer* buzzer,Note notes [], int numberOfNotes){
	for(int i=0; i < numberOfNotes;i++){
		Note n = notes[i];
		buzzer->sound(n.note,n.duration);
	}
}

void playSoundStart(Buzzer* buzzer){
	int numberOfNotes = sizeof(start_song)/sizeof(start_song[0]);
	playSound(buzzer , start_song,numberOfNotes);
}

void playSoundEnd(Buzzer* buzzer){
	int numberOfNotes = sizeof(end_song)/sizeof(end_song[0]);
	playSound(buzzer , end_song,numberOfNotes);
}

void playSoundWorking(Buzzer* buzzer){
	int numberOfNotes = sizeof(working_song)/sizeof(working_song[0]);
	playSound(buzzer , working_song,numberOfNotes);
}

void playSoundConfused(Buzzer* buzzer){
	int numberOfNotes = sizeof(confused_song)/sizeof(confused_song[0]);
	playSound(buzzer , confused_song,numberOfNotes);
}

void playSoundSleeping(Buzzer* buzzer){
	int numberOfNotes = sizeof(confused_sleeping)/sizeof(confused_sleeping[0]);
	playSound(buzzer , confused_sleeping,numberOfNotes);
}

void moveForward(){
	Serial.println("Avanzo");
	delay(3000);
}

void turnRight(){
	Serial.println("Giro Drecha");
	moveForward();
}

void turnLeft(){
	Serial.println("Giro Izquierda");
	moveForward();
}


