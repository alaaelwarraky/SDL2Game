#include "core.cpp"

int main( int argc, char* args[] )
{
	Core myGame;
	
	Background background(myGame);
	
	myGame.updateSurface();

	return 0;
}
