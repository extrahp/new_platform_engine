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
#include "global_functions.h"

BaseObject::BaseObject(int x, int y, SDL_Surface * sheet = NULL) {
    xpos = x;
    ypos = y;
    sprite_anim = 0;
    sprite_frame = 0;
    animation_speed = 0;
    animation_ticks = 0;
    for (int i = 0; i < 100; i++) 
        animation_mapping[i] = 0;
    looping = false;
    visible = true;
    velX = 0;
    velY = 0;
    gravity = 1;
    solid = false;
    display_image = NULL;
    sprite_sheet = sheet;
    frame_crop = NULL;
    animation_mapping[0] = 2;
}

void BaseObject::setX(int x) {
    xpos = x;
}

void BaseObject::setY(int y) {
    ypos = y;
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

// Function to handle all sorts of things that happen inside this object every tick
void BaseObject::update() {
    update_animation(); // update sprite animation ticks
}

SDL_Surface * BaseObject::draw(SDL_Surface * original) {
	draw_image(xpos, ypos, sprite_sheet, original, getCrop(sprite_anim, sprite_frame));
	return display_image;
}

SDL_Surface * BaseObject::getSheet() {
	return sprite_sheet;
}
void BaseObject::setSheet(SDL_Surface* sheet) {
	sprite_sheet = sheet;
}

SDL_Rect * BaseObject::getCrop(int anim, int frame) {
	return &frame_crop[anim][frame];
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

int BaseObject::getAnim() {
    return sprite_anim;
}

void BaseObject::setAnimation(int anim, int frame, int speed, bool loop) {
    sprite_anim = anim;
    sprite_frame = frame;
    animation_speed = speed;
    looping = loop;
    animation_ticks = 0; // reset frame ticking
}

int BaseObject::getFrame() {
    return sprite_frame;
}

void BaseObject::setFrame(int frame) {
    sprite_frame = frame;
    animation_ticks = 0; // reset frame ticking
}

bool BaseObject::getVisible() {
	return visible;
}

void BaseObject::setVisible(bool v) {
	visible = v;
}
// --------------------------- Private Stuff ------------------------------

void BaseObject::update_animation() {
    if (animation_speed != 0) { // if the speed is not 0
        if (animation_ticks < animation_speed) 
            animation_ticks ++; // increase tick if not passed speed-tick-count
        else {
            animation_ticks = 0; // reset the tick
            if (sprite_frame < animation_mapping[sprite_anim] - 1)
                sprite_frame ++; // move to next frame in animation if not at end
            else if (looping)
                sprite_frame = 0; // if at end and looping is true, loop back to first frame
        }
    }
}
