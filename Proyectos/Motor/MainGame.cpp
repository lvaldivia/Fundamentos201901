#include "MainGame.h"
#include "GL/glew.h"
#include <iostream>
#include "Error.h"

using namespace std;

MainGame::MainGame(): window(nullptr),width(800),
					height(600),
					gameState(GameState::PLAY),
					time(0)
{
	camera.init(width, height);
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
	glsProgram.addAtribute("vertexPosition");
	glsProgram.addAtribute("vertexColor");
	glsProgram.addAtribute("vertexUV");
	glsProgram.linkShader();
}

void MainGame::run() {
	init();
	sprites.push_back(new Sprite());
	sprites.back()->init(-1, -1, 1, 1, "Textures/mario.png");

	//sprites.push_back(new Sprite());
	//sprites.back()->init(0, -1, 1, 1, "Textures/mario.png");

	//sprite.init(-1, -1, 1, 1,"Textures/mario.png");
	update();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glsProgram.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = glsProgram.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	GLuint imageLocation = glsProgram.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	GLuint pLocation =
		glsProgram.getUniformLocation("P");

	glm::mat4 cameraMatrix = camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	time += 0.002;
	//sprite.draw();
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->draw();
	}
	glsProgram.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::update() {
	while (gameState != GameState::EXIT)
	{
		processInput();
		camera.update();
		draw();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	const float CAMERA_SPEED = 20.0f;
	const float SCALE_SPEED = 0.1f;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEBUTTONDOWN:

			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_w:
						camera.setPosition(camera.getPosition()
							+ glm::vec2(0.0, -CAMERA_SPEED)
						);
					break;
					case SDLK_s:
						camera.setPosition(camera.getPosition()
							+ glm::vec2(0.0, CAMERA_SPEED)
						);
					break;
					case SDLK_a:
						camera.setPosition(camera.getPosition()
							+ glm::vec2(CAMERA_SPEED, 0.0)
						);
						break;
					case SDLK_d:
						camera.setPosition(camera.getPosition()
							+ glm::vec2(-CAMERA_SPEED, 0.0)
						);
						break;
					case SDLK_q:
						camera.setScale(camera.getScale() + SCALE_SPEED);
						break;
					case SDLK_e:
						camera.setScale(camera.getScale() - SCALE_SPEED);
						break;
				}
			break;
		
		}
	}
}
