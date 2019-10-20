
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

Color allColors[] = { Color(19, 33, 25, ColorType::red), Color(11, 22, 21,
		ColorType::orange), Color(13, 16, 19, ColorType::yellow), Color(20, 18,
		20, ColorType::green), Color(25, 21, 15, ColorType::blue), Color(15, 22,
		14, ColorType::purple), Color(12, 27, 17, ColorType::pink), Color(23,
		27, 24, ColorType::brown) };
