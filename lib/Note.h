/*
 * Note.h
 *
 *  Created on: 20 oct. 2019
 *      Author: mike
 */

#ifndef LIB_NOTE_H_
#define LIB_NOTE_H_

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
	int frequency;
	int duration;
	Note(int frequency, int duration);
};

#endif /* LIB_NOTE_H_ */
