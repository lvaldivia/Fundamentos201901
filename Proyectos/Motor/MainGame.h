#pragma once
#include<SDL\SDL.h>
#include <GL\glew.h>
#include "Sprite.h"
#include "GLSProgram.h"
#include <vector>

enum class GameState {
	PLAY,
	EXIT
};

class MainGame{
private:
	int width;
	int height;
	Sprite sprite;
	vector<Sprite*> sprites;
	GLSProgram glsProgram;
	SDL_Window*window; 
	void init();
	void initShaders();
	float time;
public:
	MainGame();
	GameState gameState;
	~MainGame();
	void run();
	void draw();
	void update();
	void processInput();
};