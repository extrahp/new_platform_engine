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

void console_output( const std::string &text ) {
    std::ofstream log_file(
        "log_file.txt", std::ios_base::out | std::ios_base::app );
    log_file << text << std::endl;
}

CollisionBox::CollisionBox(int xpos, int ypos, int width, int height) {
	x = xpos;
	y = ypos;
	w = width;
	h = height;
	top = ypos;
	left = xpos;
	right = xpos + width;
	bottom = ypos + height;
}
