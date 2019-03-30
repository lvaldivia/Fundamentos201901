//#include <SDL\SDL.h>
#include "MainGame.h"

int main(int argc, char** argv) {
	//SDL_Init(SDL_INIT_EVERYTHING);
	MainGame mainGame;
	mainGame.run();
	system("PAUSE");
	return 0;
}