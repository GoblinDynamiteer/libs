/*
 * libgeo.h
 *
 *  Created on: 12 jan. 2017
 *      Author: kampe
 */

#ifndef LIB_LIBGEO_H_
#define LIB_LIBGEO_H_

#include <math.h>

double calculateDistance(int x1, int x2, int y1, int y2);
int deltaY(int x1, int x2);
int deltaX(int y1, int y2);
double angleArcTan(double o, double a);
double radToDeg(double rads);

#endif /* LIB_LIBGEO_H_ */
