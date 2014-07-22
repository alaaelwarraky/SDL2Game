#include "core.cpp"

class Background
{
	private:
		//The image we will load and show on the screen
		SDL_Surface* gHelloWorld = NULL;
	public:
	Background(Core myGame)
	{
		gHelloWorld = SDL_LoadPNG( "assets/Board.png" );
		myGame.loadImage(gHelloWorld);
	}
	~Background()
	{
		//Deallocate surface
		SDL_FreeSurface( gHelloWorld );
		gHelloWorld = NULL;
	}
};
