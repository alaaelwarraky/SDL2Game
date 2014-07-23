//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

class Core
{
	private:
		//Screen dimension constants
		int SCREEN_WIDTH = 1073;
		int SCREEN_HEIGHT = 571;
		
		//The window we'll be rendering to
		SDL_Window* window = NULL;
		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;
		//The image we will load and show on the screen
		SDL_Surface* HelloWorld = NULL;
		
		//takes a path to an image and loads it
		SDL_Surface* loadSurface( std::string path );
		
	public:
	
	Core();
	
	~Core();
	
	void updateSurface();
	
	void loadBackground();
};













