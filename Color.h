/*
 * Color.h
 *
 * Basic class definition that represents a RGB channels of a Color, this class can be
 * used to:
 * - Save the data of a color (the r,g,b channels ant it's type represented with an int)
 * - Given a list of know colors, determinate the type of color
 *
 *  Created on: 7 sep. 2019
 *      Author: Miguel Galindo
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
	Color(int r, int g, int b, int totalColors, Color allColors[]);
	Color(int r, int g, int b, int colorType);
	int getR();
	int getG();
	int getB();
	int getColorType();
	double getDistance(Color color);

private:
	int r;
	int g;
	int b;
	bool wellKnown;
	int colorType;
	int calculateColorType(int totalColors, Color allColors[]);
};

#endif /* COLOR_H_ */

