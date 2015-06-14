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
#include "global_functions.h"
#include <vector>

//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

//The frames per second
const int FRAMES_PER_SECOND = 60;

//The attributes of the screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;
const char* WINDOW_NAME = "Game";
Timer frame_rate_timer;
SDL_Event event;
//The images
SDL_Surface* screen = NULL;

//TEST VARIABLES
SDL_Surface * bearSprite = NULL;
SDL_Surface * platSprite = NULL;
SDL_Surface * bg = NULL;
BaseObject * test;
BaseObject * platform;
BaseObject * things [2];
std::vector<BaseObject> all_objects;


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
        //Create an optimized image
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

// -------------------------------------------------------------------------------------------------------------------

bool load_files() {
    //Load the images
    bearSprite = load_image("bear1.png");
    platSprite = load_image("platform.png");
    bg = load_image("bg.png");
    return true;
}

void game_tick() {
	test->update(all_objects);
	platform->update(all_objects);
	draw_image(0, 0, bg, screen);
	test->draw(screen);
	platform->draw(screen);
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
	test = new BaseObject(565, 200, bearSprite);
	test->setCrop(31, 49, 1, 2);
	test->setAnimation(0, 0, 12, true);
	test->setClsn(31, 49, 15, 49);
	test->setOrigin(15, 49);
	test->setGravity(0);
	platform = new BaseObject(550, 400, platSprite);
	platform->setCrop(100, 30, 1, 1);
	platform->setClsn(100, 30);
	platform->setSolid(true);
	platform->setGravity(0);
	things[0] = test;
	things[1] = platform;
	all_objects.push_back(*test);
	all_objects.push_back(*platform);

	while (!game_end) {
		frame_rate_timer.start();
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
		if (frame_rate_timer.get_ticks() < 1000 / FRAMES_PER_SECOND ) {
			SDL_Delay(( 1000 / FRAMES_PER_SECOND ) - frame_rate_timer.get_ticks());
		}

	}
    //Quit SDL
    SDL_Quit();
    return 0;
}

//---------------------------------------------------- Timer --------------------------------------------------------
Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;
}

int Timer::get_ticks()
{
    //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

void Timer::pause()
{
    //If the timer is running and isn't already paused
    if( ( started == true ) && ( paused == false ) )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    //If the timer is paused
    if( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}
