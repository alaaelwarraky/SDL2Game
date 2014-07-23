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
		
		SDL_Surface* loadSurface( std::string path )
		{
			//The final optimized image
			SDL_Surface* optimizedSurface = NULL;
		
			//Load image at specified path
			SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		
			if( loadedSurface == NULL )
				printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
			else
			{
				//Convert surface to screen format
				optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, NULL );
			
				if( optimizedSurface == NULL )
					printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			
				//Get rid of old loaded surface
				SDL_FreeSurface( loadedSurface );
			}
			
			return optimizedSurface;
		}
		
	public:
	
	Core()
	{
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Create window
			window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			
			if( window == NULL )
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			else
				screenSurface = SDL_GetWindowSurface( window );
		}
	}
	
	~Core()
	{
		
		SDL_FreeSurface( HelloWorld );
		HelloWorld = NULL;
		
		//Destroy window
		SDL_DestroyWindow( window );

		//Quit SDL subsystems
		SDL_Quit();
	}
	
	void updateSurface()
	{
		//Update the surface
		SDL_UpdateWindowSurface( window );
	}
	
	void loadBackground()
	{
		HelloWorld = loadSurface("assets/Board.png");
		
		if( HelloWorld == NULL )
			printf( "Unable to load image %s! SDL Error: %s\n", "assets/Board.png", SDL_GetError() );
		
		SDL_BlitSurface( HelloWorld, NULL, screenSurface, NULL );
	}
};













