/*
 * base_object.h
 *
 *  Created on: May 27, 2015
 *      Author: Kay
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

class BaseObject {
    public:
		BaseObject(int x, int y, SDL_Surface *); // Constructor
        void setX(int x); // set specific X position
        void setY(int y); // set specific Y position
        int getX(); // get current X position
        int getY(); // get current Y position
        void update(); // update ticks
        void setVelX(int x); // set a horizontal speed
        void setVelY(int y); // set a vertical speed
        int getVelX(); // get the current horizontal speed
        int getVelY(); // get the current vertical speed
        bool getGravity(); // get the gravity multiplier
        void setGravity(int g); // set a gravity multiplier (0 to 1)
        bool isSolid(); // check if is solid object (can phase through or not)
        void setSolid(bool s); // set solid or not
        SDL_Surface * getCurrentImage(); // return the current image based on animation and frame
        void setSheet(SDL_Surface*); // set the sprite sheet for this object
        SDL_Surface * getSheet(); // get the sprite sheet for this object
        SDL_Rect * getCrop(int x, int y); // get the frame crop
        void setCrop(int w, int h, int r, int c); // set the default frame crops with frame width, height, and number of rows and columns
        int getAnim(); // get the current animation
        void setAnimation(int anim, int speed, bool loop); // set a new animation with speed and looping?
        int getFrame(); // get the current frame of the animation
        void setFrame(int frame); // set a new frame of the animation
    private:
        int sprite_frame;
        int sprite_anim;
        int velX;
        int velY;
        int xpos;
        int ypos;
        int gravity;
        bool solid;
        SDL_Surface * display_image;
        SDL_Surface * sprite_sheet;
        SDL_Rect ** frame_crop;

};

#endif /* BASE_OBJECT_H_ */
