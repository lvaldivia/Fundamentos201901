#pragma once
#include<SDL\SDL.h>
#include <GL\glew.h>
#include "Sprite.h"
#include "GLSProgram.h"

enum class GameState {
	PLAY,
	EXIT
};

class MainGame{
private:
	int width;
	int height;
	Sprite sprite;
	GLSProgram glsProgram;
	SDL_Window*window; 
	void init();
	void initShaders();
public:
	MainGame();
	GameState gameState;
	~MainGame();
	void run();
	void draw();
	void update();
	void processInput();
};