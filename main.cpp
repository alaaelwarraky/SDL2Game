#include "core.cpp"

int main( int argc, char* args[] )
{
	Core myGame;
	
	myGame.loadBackground();
	
	myGame.updateSurface();

	return 0;
}
