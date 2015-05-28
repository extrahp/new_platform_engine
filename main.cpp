/*
 * SDL_test.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include "base_object.h"
#include <string>
#include <sstream>

//The attributes of the screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;
const char* WINDOW_NAME = "Game";
SDL_Event event;
//The images
SDL_Surface* screen = NULL;

//TEST VARIABLES
SDL_Surface * bearSprite = NULL;
BaseObject * test;

// ----------------------------------------------------- Core SDL Functions --------------------------------------------------------------
SDL_Surface * load_image(std::string filename ) {

    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL ) {
    	SDL_WM_SetCaption( "HI", NULL );
        //Create an optimized image
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect * clip = NULL) {
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, clip, destination, &offset );
}

// -------------------------------------------------------------------------------------------------------------------

bool load_files() {
    //Load the images
    bearSprite = load_image("bear1.png");
    //If there was an error in loading the image
    if(bearSprite == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void game_tick() {
	apply_surface(test->getX(), test->getY(), test->getSheet(), screen, test->getCrop(0, 0));
	return;
}

int main( int argc, char* args[] ) {

	bool game_end = false;

    //Start SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
		return false;
	}

    //Set the window caption
    SDL_WM_SetCaption( WINDOW_NAME, NULL );

    //Set up screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    //If there was an error in setting up the screen
	if( screen == NULL ) {
		return 1;
	}

	if (!load_files()) {
		game_end = true;
	}

	test = new BaseObject(600, 400, bearSprite);
	test->setCrop(31, 49, 1, 2);

	while (!game_end) {
		game_tick();
		while (SDL_PollEvent(&event)) {
			if( event.type == SDL_QUIT ) {
				game_end = true;
			}

		}
		//Update Screen
		if( SDL_Flip( screen ) == -1 ) {
			return 1;
		}
	}
    //Quit SDL
    SDL_Quit();

    return 0;
}


