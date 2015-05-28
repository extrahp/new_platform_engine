/*
 * global_functions.cpp
 *
 *  Created on: May 28, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "global_functions.h"

void draw_image(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect * clip) {
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface( source, clip, destination, &offset );
}
