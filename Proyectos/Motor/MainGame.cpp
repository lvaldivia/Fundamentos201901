#include "MainGame.h"



MainGame::MainGame()
{

}

MainGame::~MainGame() {
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window =
		SDL_CreateWindow(
			"Holi :D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL
		);
	if (window == nullptr) {
		//secayo
	}
	SDL_GLContext glContext =
		SDL_GL_CreateContext(window);

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//se cayo
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::run() {
	init();
	update();
}

void MainGame::draw() {
}

void MainGame::update() {
}