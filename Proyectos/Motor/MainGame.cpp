#include "MainGame.h"
#include "GL/glew.h"
#include <iostream>
#include "Error.h"

using namespace std;

MainGame::MainGame(): window(nullptr),width(800),
					height(600),
					gameState(GameState::PLAY)
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
		fatalError("SDL no se pudo inicializar");
	}
	SDL_GLContext glContext =
		SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew no se pudo inicializar");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders()
{
	glsProgram.compileShaders("Shaders/colorShaderVert.txt"
								, "Shaders/colorShaderFrag.txt");
	glsProgram.linkShader();
	glsProgram.addAtribute("vertexPosition");
	glsProgram.addAtribute("vertexColor");

}

void MainGame::run() {
	init();
	sprite.init(-1, -1, 1, 1);
	update();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//se dibujaran los elementos en pantalla
	glsProgram.use();
	sprite.draw();
	glsProgram.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::update() {
	while (gameState != GameState::EXIT)
	{
		processInput();
		draw();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEBUTTONDOWN:
			
			break;
		/*case SDL_MOUSEMOTION:
			cout
				<< "pos x " << event.motion.x
				<< " pos y " << event.motion.y;
			break;*/
		}
	}
}
