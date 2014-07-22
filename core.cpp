//Using SDL and standard IO
#include<SDL2/SDL.h>
#include <stdio.h>

class Core
{
	private:
		//Screen dimension constants
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		
		//The window we'll be rendering to
		SDL_Window* window = NULL;
		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;
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

				//Fill the surface white
				SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			}
		}
	}
	
	~Core()
	{
		//Wait two seconds
		SDL_Delay( 2000 );
		
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
	
	void loadImage(SDL_Surface* image)
	{
		SDL_BlitSurface( image, NULL, screenSurface, NULL );
	}
};













