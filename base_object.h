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
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        int getFrame();
        BaseObject(int x, int y, SDL_Surface *);
        void update();
        void setVelX(int x);
        void setVelY(int y);
        int getVelX();
        int getVelY();
        bool getGravity();
        void setGravity(int g);
        bool isSolid();
        void setSolid(bool s);
        SDL_Surface * getCurrentImage();
        void setImage(SDL_Surface*);
        void setSheet(SDL_Surface*);
        SDL_Surface * getSheet();
        void setCrop(int w, int h, int r, int c);
        SDL_Rect * getFrame(int x, int y);
    private:
        int spriteframe;
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
