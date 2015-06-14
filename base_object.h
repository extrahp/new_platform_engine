/*
 * base_object.h
 *
 *  Created on: May 27, 2015
 *      Author: Kay
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "global_functions.h"
#include <vector>

#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

class BaseObject;

// An element of an object
class BaseElement {
    public:
		BaseElement(BaseObject * parent); // Constructor
        BaseObject * getParent();
        void run();
    private:
        BaseObject * parent;
        void on_start();
        void on_tick(); // update ticks
        bool initial_tick;
};

class BaseObject {
    public:
		BaseObject(int x, int y, SDL_Surface *); // Constructor
        void setX(int x); // set specific X position
        void setY(int y); // set specific Y position
        int getX(); // get current X position
        int getY(); // get current Y position
        void setVelX(float x); // set a horizontal speed
        void setVelY(float y); // set a vertical speed
        float getVelX(); // get the current horizontal speed
        float getVelY(); // get the current vertical speed
        bool getGravity(); // get the gravity multiplier
        void setGravity(float g); // set a gravity multiplier (0 to 1)
        bool isSolid(); // check if is solid object (can phase through or not)
        void setSolid(bool s); // set solid or not
        SDL_Surface * draw(SDL_Surface * original); // return the current image based on animation and frame
        void setSheet(SDL_Surface*); // set the sprite sheet for this object
        SDL_Surface * getSheet(); // get the sprite sheet for this object
        SDL_Rect * getCrop(int x, int y); // get the frame crop
        void setCrop(int w, int h, int r, int c); // set the default frame crops with frame width, height, and number of rows and columns
        int getAnim(); // get the current animation
        void setAnimation(int anim, int frame, int speed, bool loop = true); // set a new animation with speed and looping?
        int getFrame(); // get the current frame of the animation
        void setFrame(int frame); // set a new frame of the animation
        bool getVisible(); // get if object is visible or not
        void setVisible(bool v); // set the visibility
        void update(std::vector<BaseObject> objects); // update ticks
        CollisionBox * getClsn();
        void setClsn(int w, int h, int x = 0, int y = 0);
        bool isColliding(CollisionBox * other);
        void setOrigin(int x, int y);
        int getOriginX();
        int getOriginY();
        void add(BaseElement * el);
    private:
        int sprite_frame;
        int sprite_anim;
        int animation_speed;
        int animation_ticks;
        int animation_mapping[100];
        int originXoffset;
        int originYoffset;
        bool looping;
        bool visible;
        float velX;
        float velY;
        float xpos;
        float ypos;
        float gravity;
        bool solid;
        SDL_Surface * display_image;
        SDL_Surface * sprite_sheet;
        SDL_Rect ** frame_crop;
        void update_animation(); //helper function to handle graphical aspect of object
        CollisionBox * clsn;
        std::vector<BaseElement *> elements;
};

#endif /* BASE_OBJECT_H_ */
