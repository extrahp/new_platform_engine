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

void draw_image(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect * clip);

void console_output( const std::string &text);

class CollisionBox {
    public:
		CollisionBox(int x, int y, int w, int h); // Constructor
        int x;
        int y;
        int w;
        int h;
        int top;
        int left;
        int right;
        int bottom;
};

#endif /* GLOBAL_FUNCTIONS_H_ */
