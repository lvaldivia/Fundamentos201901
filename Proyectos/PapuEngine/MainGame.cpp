#include "MainGame.h"
#include "Sprite.h"
#include "ImageLoader.h"
#include <iostream>
#include "PapuEngine.h"

using namespace std;

void MainGame::run() {
	init();
	/*_sprites.push_back(new Sprite());
	_sprites.back()->init(0.0f, 0.0f, _witdh/2, _witdh/2, "Textures/Paper_Mario_.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(_witdh/2, _height/2, _witdh / 2, _witdh / 2, "Textures/Paper_Mario_.png");*/
	update();
}

void MainGame::init() {
	Papu::init();
	_window.create("Engine", _witdh, _height, 0);
	initShaders();
	initLevel();
}

void MainGame::initLevel() {
	currentLevel = 0;
	levels.push_back(new Level("Level/level1.txt"));
	spritebatch.init();
	player = new Player();
	player->init(0.10f, 
			levels[currentLevel]->getPlayerPosition(),
		&inputManager);
}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);

	/*GLuint timeLocation =
		_program.getUniformLocation("time");

	glUniform1f(timeLocation,_time);*/

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);


	spritebatch.begin();
	levels[currentLevel]->draw();
	player->draw(spritebatch);
	spritebatch.end();
	spritebatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);
	
	_program.unuse();
	
	_window.swapBuffer();
}

void MainGame::procesInput() {
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				inputManager.setMouseCoords(event.motion.x,
					event.motion.y);
			break;
			case SDL_KEYUP:
				inputManager.releaseKey(event.key.keysym.sym);
				break;
			case  SDL_KEYDOWN:
				inputManager.pressKey(event.key.keysym.sym);
				break;
		}
	}
	handleInput();

}

void MainGame::handleInput()
{
	const float CAMERA_SPEED = 0.02;
	const float SCALE_SPEED = 0.001f;
	if (inputManager.isKeyPressed(SDLK_w)) {
		_camera.setPosition(_camera.getPosition() 
					+glm::vec2(0.0, CAMERA_SPEED));
	}
	if (inputManager.isKeyPressed(SDLK_s)) {
		_camera.setPosition(_camera.getPosition() 
				- glm::vec2(0.0, CAMERA_SPEED));
	}
	if (inputManager.isKeyPressed(SDLK_a)) {
		_camera.setPosition(_camera.getPosition() 
				- glm::vec2(CAMERA_SPEED, 0.0));
	}
	if (inputManager.isKeyPressed(SDLK_d)) {
		_camera.setPosition(_camera.getPosition() 
				+ glm::vec2(CAMERA_SPEED, 0.0));
	}
	if (inputManager.isKeyPressed(SDLK_q)) {
		_camera.setScale(_camera.getScale() + SCALE_SPEED);
	}
	if (inputManager.isKeyPressed(SDLK_e)) {
		_camera.setScale(_camera.getScale() - SCALE_SPEED);
	}
}

void MainGame::update() {

	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		_camera.update();
		_time += 0.002f;
	}
}


MainGame::MainGame(): 
					  _witdh(800),
					  _height(600),
					  _gameState(GameState::PLAY),
					  _time(0)
{
	_camera.init(_witdh, _height);
}


MainGame::~MainGame()
{
}
