#include <Buzzer.h>


#define EIGHT  50
#define DOTTED_EIGHT  (EIGHT) + (EIGHT/2)

#define QUARTER  EIGHT*2
#define QUARTER_DOTTED  (QUARTER)+(EIGHT)

#define HALF  QUARTER*2
#define HALF_DOTTED   (HALF) + (QUARTER)

#define WHITE  HALF * 2
#define WHITE_DOTTED  (WHITE) + (HALF)

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
  Note(NOTE_FS7 , WHITE),
  Note(NOTE_DS7,QUARTER),
  Note(NOTE_FS7 , WHITE),
  Note(NOTE_DS7,QUARTER),
  Note(NOTE_B7 , WHITE_DOTTED),
};

Note end_song[] = {
  Note(NOTE_B7,QUARTER),
  Note(NOTE_DS7 , QUARTER),
  Note(NOTE_FS7,WHITE),
  Note(0,EIGHT),
  Note(NOTE_FS7 , EIGHT),
  Note(0,EIGHT),
  Note(NOTE_FS7,QUARTER),
  Note(NOTE_B7 , WHITE_DOTTED)
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
  Note(NOTE_DS8,HALF),
  Note(0,EIGHT),
  Note(NOTE_GS8 ,HALF)
};

Note confused_sleeping[] = {
  Note(NOTE_DS7,HALF),
  Note(0,EIGHT),
  Note(NOTE_DS7,HALF),
  Note(NOTE_FS7,WHITE_DOTTED),
  Note(0,WHITE),
  Note(NOTE_DS7,HALF),
  Note(0,EIGHT),
  Note(NOTE_DS7,HALF),
  Note(NOTE_FS7,WHITE_DOTTED),
};
