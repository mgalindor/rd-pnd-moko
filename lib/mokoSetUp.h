#include "Color.h"

#define STEPS 2048

/*
 * PIN Configuration - Color Sensor TCS3200
 */
//const int col_s0 = NA; // Configured Externally
//const int col_s1 = NA; // Configured Externally
const int col_s2 = 2;
const int col_s3 = 3;
const int col_out = 4;

/*
 * PIN Configuration - ULN2003/28BYJ-48
 */
const int mR_in1 = 5;
const int mR_in2 = 6;
const int mR_in3 = 7;
const int mR_in4 = 8;

const int mL_in1 = 9;
const int mL_in2 = 10;
const int mL_in3 = 11;
const int mL_in4 = 12;

/*
 * PIN Configuration - Buzzer
 */
const int bzz_in = 13;

/*
 * Color First SetUp
 */
enum ColorType {
	NF, red, orange, yellow, green, blue, purple, pink, brown
};

const Color allColors[] = { Color(17,58,41, ColorType::red),
		Color(11,29,30, ColorType::orange),
		Color(10,15,23, ColorType::yellow),
		Color(26,18,27, ColorType::green),
		Color(45,19,11, ColorType::blue),
		Color(30,30,15, ColorType::purple),
		Color(9,35,18,ColorType::pink),
		Color(27,39,40, ColorType::brown) };

