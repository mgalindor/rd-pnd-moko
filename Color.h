/*
 * Color.h
 *
 *  Created on: 7 sep. 2019
 *      Author: Miguel Galindo
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
	Color(int r, int g, int b,int totalColors, Color allColors[]);
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
	int colorType;
	int calculateColorType(int totalColors, Color allColors[]);
};

#endif /* COLOR_H_ */

