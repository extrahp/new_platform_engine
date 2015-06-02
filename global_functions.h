/*
 * global_functions.h
 *
 *  Created on: May 28, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <fstream>

#ifndef GLOBAL_FUNCTIONS_H_
#define GLOBAL_FUNCTIONS_H_

bool keyboard_pressed(int key);

bool keyboard_down(Uint8 * current, int key);

bool keyboard_up(Uint8 * current, int key);

void draw_image(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect * clip = NULL);

void console_output( const std::string &text);

std::string toString(int i);

class CollisionBox {
    public:
		CollisionBox(int x, int y, int w, int h, int offX = 0, int offY = 9); // Constructor
		int offsetX;
		int offsetY;
        int w;
        int h;
        int top;
        int left;
        int right;
        int bottom;
        void update(int x, int y);
};

#endif /* GLOBAL_FUNCTIONS_H_ */
