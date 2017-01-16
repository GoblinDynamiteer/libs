/*
 * libgeo.c
 *
 *  Created on: 12 jan. 2017
 *      Author: Johan Kämpe
 */

#include "libgeo.h"

/*	 Calculate distance between two coordinates	*/
double calculateDistance(int x1, int x2, int y1, int y2){
	 double calc =
		sqrt(
		pow((float)x1 - (float)x2, 2) +
		pow((float)y1 - (float)y2, 2)
	);
	return calc;
}

int deltaY(int x1, int x2){
	return x1 - x2;
}

int deltaX(int y1, int y2){
	return y1 - y2;
}

/*	 Angle from opposite and adjacent sides of a triangle	*/
double angleArcTan(double o, double a){
	return atan (o / a);
}

/*	 Converts radians to degrees	*/
double radToDeg(double rads){
	return rads * 180.0 / M_PI;
}

double lineSlope(double deltaX, double deltaY){
	return deltaY / deltaX;
}
