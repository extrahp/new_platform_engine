/*
 * SDL_test.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Kay
 */

#include "SDL/SDL.h"
#include <iostream>

//The attributes of the screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

int main( int argc, char* args[] )
{
	//The images
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //Set up screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	//Load image
	hello = SDL_LoadBMP( "hello.bmp" );

	//Apply image to screen
	SDL_BlitSurface( hello, NULL, screen, NULL );

	//Update Screen
	SDL_Flip( screen );

	//Pause
	SDL_Delay( 500 );

	//Free the loaded image
	SDL_FreeSurface( hello );

    //Quit SDL
    SDL_Quit();

    return 0;
}


