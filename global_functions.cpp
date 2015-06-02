/*
 * global_functions.cpp
 *
 *  Created on: May 28, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "global_functions.h"
#include <string>
#include <sstream>

bool keyboard_pressed(int key) {
	Uint8 * keyboard_check = SDL_GetKeyState(NULL);
	return keyboard_check[key];
}

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

std::string toString(int i) {
	std::string test;
	std::ostringstream convert;
	convert << i;
	test = convert.str();
	return test;
}

CollisionBox::CollisionBox(int x, int y, int width, int height, int offX, int offY) {
	offsetX = offX;
	offsetY = offY;
	w = width;
	h = height;
	top = y;
	left = x;
	right = x + width;
	bottom = y + height;
}

void CollisionBox::update(int xpos, int ypos) {
	top = ypos - offsetY;
	left = xpos - offsetX;
	right = left + w;
	bottom = top + h;
}
