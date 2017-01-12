/*
 * def.h
 *
 *  Created on: 8 jan. 2017
 *      Author: kampe_000
 */

/*	 Include guard	*/
#ifndef DEF_H_
#define DEF_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

/*	 Window dimensions, FULL HD!	*/
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

/*	 Flags for window	*/
#define WIN_FLAGS 0//SDL_WINDOW_FULLSCREEN
#define REN_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

/*	 Font stuff	*/
#define FONT_SIZE 28

/* Struct for holding test info */
typedef struct test{
	SDL_Window * window;
	SDL_Renderer * renderer;
	int originX, originY;
	int mouseX, mouseY;
	double distance;
	double angle;
	int deltaY, deltaX;
	TTF_Font *font;
}test;


/*	 Functions	*/
bool processEvent(test * test);
bool render(test * test);
void drawText(test * test, char * text, int x, int y);

#endif /* DEF_H_ */
