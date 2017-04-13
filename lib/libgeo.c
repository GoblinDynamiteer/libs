/*  
		Geometry functions

		by Johan Kämpe
    https://www.linkedin.com/in/johankampe/
    https://github.com/GoblinDynamiteer/

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

double perpendLineSlope(double slope){
	/*	 negative reciprocal	*/
	return -(1.0f/slope);
}


double perpendLineCos(double slope){
	double c = 1.0f / (sqrt(1.0f+pow(slope,2)));
	return c;

}

double perpendLineSin(double slope){
	double s = slope / (sqrt(1.0f+pow(slope,2)));
	return s;

}


/*	Functions determines end coordinates from X,Y starting coordinate,
 * 	slope, and length of line.	*/

int lineEndCoordXpos(int xStart, double lineLenght, double slope){
	double c = perpendLineCos(slope);
	int xEnd = xStart + (int)(lineLenght * c);
	return xEnd;
}

int lineEndCoordXneg(int xStart, double lineLenght, double slope){
	double c = perpendLineCos(slope);
	int xEnd = xStart - (int)(lineLenght * c);
	return xEnd;
}

int lineEndCoordYpos(int yStart, double lineLenght, double slope){
	double s = perpendLineSin(slope);
	int yEnd = yStart + (int)(lineLenght * s);
	return yEnd;
}

int lineEndCoordYneg(int yStart, double lineLenght, double slope){
	double s = perpendLineSin(slope);
	int yEnd = yStart - (int)(lineLenght * s);
	return yEnd;
}
