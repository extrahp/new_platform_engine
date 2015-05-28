/*
 * global_functions.h
 *
 *  Created on: May 28, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#ifndef GLOBAL_FUNCTIONS_H_
#define GLOBAL_FUNCTIONS_H_

void draw_image(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect * clip);

#endif /* GLOBAL_FUNCTIONS_H_ */
