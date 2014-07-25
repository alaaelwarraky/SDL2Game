#include "Board.h"

int main( int argc, char* args[] )
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	
	Board myGame;
	
	myGame.loadBackground();
	
	//While application is running
	while( !quit )
	{
		myGame.updateSurface();
		
		while( SDL_PollEvent( &e ) != 0 )
			if( e.type == SDL_QUIT ) //User requests quit
				quit = true;
	}
	
	return 0;
}
