#pragma once
#include<SDL\SDL.h>
#include <GL\glew.h>

enum class GameState {
	PLAY,
	EXIT
};

class MainGame{
private:
	int width;
	int height;
	SDL_Window*window; 
	void init();
public:
	MainGame();
	GameState gameState;
	~MainGame();
	void run();
	void draw();
	void update();
};