/*
 * main.c
 *
 *  Created on: 8 jan. 2017
 *      Author: kampe_000
 */

#include "def.h"
#include "..\lib\libgeo.h"

int main(int argc, char *argv[]){
	/*	 Init SDL	*/
    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    /*	 Hide cursor	*/
    //SDL_ShowCursor(SDL_DISABLE);

    /*	 Declare window and renderer	*/
    SDL_Window * window;
    SDL_Renderer * renderer;

    /*	 Create window	*/
	window = SDL_CreateWindow(
		"libgeo!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIN_WIDTH,
		WIN_HEIGHT,
		WIN_FLAGS
	);

    /*	 Create renderer	*/
	renderer = SDL_CreateRenderer(
			window,
			-1,
			REN_FLAGS
	);

	/*	Struct 	*/
	test test;
	test.originX = WIN_WIDTH /2;
	test.originY = WIN_HEIGHT /2;
	test.renderer = renderer;
	test.window = window;

	test.font = TTF_OpenFont("test/font/joystix_monospace.ttf", FONT_SIZE);

    /*	 Test loop	*/

    while(processEvent(&test)){
    	if(!render(&test)){
    		break;
    	}
    	SDL_Delay(1000/60);
    }

    /*	 Quit SDL	*/
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();


	return 0;
}

bool processEvent(test * test){
	/*	 Event union	*/
	SDL_Event event;

	while(SDL_PollEvent(&event)){
		Uint32 type = event.type;
		switch(type){
			/*	 Close button is pressed	*/
			case SDL_WINDOWEVENT:
				if(event.window.event == SDL_WINDOWEVENT_CLOSE){
					return 0;
				}
				break;
			/*	 A key has been pressed	*/
			case SDL_KEYDOWN:
				if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
					return 0;
				}
				break;
		}
	}

	SDL_GetMouseState(&test->mouseX, &test->mouseY);

	test->distance = calculateDistance(
			test->mouseX,
			test->originX,
			test->mouseY,
			test->originY
	);

	test->deltaY = deltaY(test->originY, test->mouseY);
	test->deltaX = deltaX(test->originX, test->mouseX);

	test->lineSlope = lineSlope(test->deltaX, test->deltaY);

	double angleRad =  angleArcTan(test->deltaY, test->deltaX);
	test->angle = radToDeg(angleRad);

	return 1;
}


bool render(test * test){
	/*	 Draw background color	*/
	SDL_SetRenderDrawColor(test->renderer, 0, 0, 255, 255);
	SDL_RenderClear(test->renderer);

	/*	 Draw line between origin and mouse position	*/
	SDL_SetRenderDrawColor(test->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(
			test->renderer,
			test->originX,
			test->originY,
			test->mouseX,
			test->mouseY
	);

	/*	 Draw horizontal line 	*/
	SDL_RenderDrawLine(
			test->renderer,
			test->originX,
			test->originY,
			test->mouseX,
			test->originY
	);

	/*	 Draw vertical line 	*/
	SDL_RenderDrawLine(
			test->renderer,
			test->mouseX,
			test->originY,
			test->mouseX,
			test->mouseY
	);

	int dypos = test->mouseY + test->deltaY / 2;
	int dxpos = test->originX - test->deltaX / 2;

	/*	 Display text	*/
	char displayText[80];
	SDL_Color color = {255,255,255};
	sprintf(displayText, "Distance: %.2f", test->distance);
	drawText(test, displayText, test->mouseX, test->mouseY-20, color);

	sprintf(displayText, "dX: %d", test->deltaX);
	drawText(test, displayText, dxpos, test->originY+10, color);

	sprintf(displayText, "dY: %d", test->deltaY);
	drawText(test, displayText, test->mouseX, dypos, color);

	sprintf(displayText, "Angle: %.2f", test->angle);
	drawText(test, displayText, test->originX, test->originY-20, color);

	sprintf(displayText, "Slope: %.2f", test->lineSlope);
	drawText(test, displayText, 10, 10, color);

	/*	Calculate and draw perpendicular line	*/
	double perpSlope = perpendLineSlope(test->lineSlope);

	/*	 Staring position is middle of triangle hypotenuse	*/
	int xStart = test->mouseX + test->deltaX / 2;
	int yStart = test->mouseY + test->deltaY / 2;

	/*	 Draw perpendicular line and text with other colour	*/

	color.r = 0;
	color.g = 200;
	color.b = 220;
	SDL_SetRenderDrawColor(test->renderer, 0, 200, 220, 255);
	sprintf(displayText, "Perpendicular slope: %.2f", perpSlope);
	drawText(test, displayText, 10, 10 + FONT_SIZE, color);

	SDL_RenderDrawLine(
			test->renderer,
			lineEndCoordXpos(xStart, PERPLINE_SIZE, perpSlope),
			lineEndCoordYpos(yStart, PERPLINE_SIZE, perpSlope),
			lineEndCoordXneg(xStart, PERPLINE_SIZE, perpSlope),
			lineEndCoordYneg(yStart, PERPLINE_SIZE, perpSlope)
	);

	SDL_RenderPresent(test->renderer);
	return 1;
}

/*	 Draw text	*/
void drawText(test * test, char * text, int x, int y, SDL_Color color){

	SDL_Surface *textSurface;
	//SDL_Color color = {255,255,255};

	textSurface = TTF_RenderText_Solid(
		test->font, text, color
	);

	SDL_Texture * textTexture = SDL_CreateTextureFromSurface(
		test->renderer, textSurface
	);
	SDL_Rect textRect = {x, y, 0, 0};
	SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(test->renderer, textTexture, NULL, &textRect);
}
