//Using SDL and standard IO
#include<SDL2/SDL.h>
#include <stdio.h>

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
			{
				printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			}
			else
			{
				screenSurface = SDL_GetWindowSurface( window );
			}
		}
	}
	
	~Core()
	{
		//Wait two seconds
		SDL_Delay( 2000 );
		
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
		HelloWorld = SDL_LoadBMP( "assets/Board.bmp" );
		
		if( HelloWorld == NULL )
			printf( "Unable to load image %s! SDL Error: %s\n", "assets/Board.bmp", SDL_GetError() );
		
		SDL_BlitSurface( HelloWorld, NULL, screenSurface, NULL );
	}
};













