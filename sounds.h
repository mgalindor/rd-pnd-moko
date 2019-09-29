#include <Buzzer.h>

#define WHITE  400
#define HALF_DOTTED  WHITE + (WHITE/2)
#define HALF  WHITE/2
#define QUARTER_DOTTED  HALF_DOTTED/2
#define QUARTER  HALF/2
#define DOTTED_EIGHT  QUARTER_DOTTED/2
#define EIGHT  QUARTER/2

class Note {
public:
	int note;
	int duration;
	Note(int n, int d) {
		note = n;
		duration = d;
	}
};

Note start_song[] = {
	Note(NOTE_DS7,QUARTER),
	Note(NOTE_FS7 , QUARTER_DOTTED),
	Note(NOTE_DS7,QUARTER),
	Note(NOTE_FS7 , QUARTER_DOTTED),
	Note(NOTE_DS7,QUARTER),
	Note(NOTE_B7 , QUARTER_DOTTED),
};

Note end_song[] = {
	Note(NOTE_B7,QUARTER),
	Note(NOTE_DS7 , QUARTER),
	Note(NOTE_FS7,QUARTER_DOTTED),
	Note(0,EIGHT),
	Note(NOTE_FS7 , EIGHT),
	Note(0,EIGHT),
	Note(NOTE_FS7,QUARTER),
	Note(NOTE_B7 , HALF_DOTTED)
};

Note working_song[] = {
	Note(NOTE_DS7,HALF),
	Note(0,QUARTER),
	Note(NOTE_FS7,HALF),
	Note(0,EIGHT),
	Note(NOTE_DS7,HALF),
	Note(0,QUARTER),
	Note(NOTE_FS7,HALF),
};

Note confused_song[] = {
	Note(NOTE_AS7,EIGHT),
	Note(NOTE_B7 , DOTTED_EIGHT),
	Note(NOTE_AS7,EIGHT),
	Note(NOTE_B7 , DOTTED_EIGHT),
	Note(NOTE_AS7,EIGHT),
	Note(NOTE_B7 , DOTTED_EIGHT)
};

Note confused_sleeping[] = {
	Note(NOTE_DS7,HALF),
	Note(0,EIGHT),
	Note(NOTE_DS7,HALF),
	Note(NOTE_FS7,WHITE),
	Note(0,WHITE),
	Note(NOTE_DS7,HALF),
	Note(0,EIGHT),
	Note(NOTE_DS7,HALF),
	Note(NOTE_FS7,WHITE),
};
