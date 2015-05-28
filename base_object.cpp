/*
 * base_object.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Kay
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <sstream>
#include "base_object.h"

BaseObject::BaseObject(int x, int y, SDL_Surface * sheet = NULL) {
    xpos = x;
    ypos = y;
    sprite_anim = 0;
    sprite_frame = 0;
    velX = 0;
    velY = 0;
    gravity = 1;
    solid = false;
    display_image = NULL;
    sprite_sheet = sheet;
    frame_crop = NULL;
}

void BaseObject::setX(int x) {
    xpos = x;
}

void BaseObject::setY(int y) {
    ypos = y;
}

void BaseObject::update() {
}

int BaseObject::getX() {
    return xpos;
}

int BaseObject:: getY() {
    return ypos;
}

int BaseObject::getVelX() {
    return velX;
}

int BaseObject:: getVelY() {
    return velY;
}

SDL_Surface * BaseObject:: getCurrentImage() {
	return display_image;
}

SDL_Surface * BaseObject::getSheet() {
	return sprite_sheet;
}
void BaseObject::setSheet(SDL_Surface* sheet) {
	sprite_sheet = sheet;
}

SDL_Rect * BaseObject::getCrop(int x, int y) {
	return &frame_crop[x][y];
}
void BaseObject::setCrop(int w, int h, int row, int col) {
	SDL_Rect ** new_frame_crop = new SDL_Rect * [col];
	for(int i = 0; i < row; i++) {
		new_frame_crop[i] = new SDL_Rect [col];
		for(int j = 0; j < col; j++) {
			new_frame_crop[i][j].x = 0 + (j * w);
			new_frame_crop[i][j].y = 0 + (i * h);
			new_frame_crop[i][j].w = w;
			new_frame_crop[i][j].h = h;
		}
	}
	frame_crop = new_frame_crop;
}
