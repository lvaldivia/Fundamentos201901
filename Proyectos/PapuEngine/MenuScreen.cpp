#include "MenuScreen.h"
#include "ScreenIndices.h"
#include "SpriteBatch.h"
#include "Camera2D.h"
#include "SpriteFont.h"



MenuScreen::MenuScreen(Window* _window): window(_window)
{
	screenIndex = SCREEN_INDEX_MENU;
}


void MenuScreen::initSystem() {
	program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

int MenuScreen::getNextScreen() const
{
	return SCREEN_INDEX_GAME;
}

int MenuScreen::getPreviousScreen() const
{
	return SCREEN_INDEX_NO_SCREEN;
}

void MenuScreen::build() {

}

void MenuScreen::destroy() {}

void MenuScreen::onEntry(){
	initSystem();
	camera2d.init(window->getScreenWidth(),
		window->getScreenHeight());
	camera2d.setScale(32.0f);

	cameraHud.init(window->getScreenWidth(),
		window->getScreenHeight());
	camera2d.setPosition(
		glm::vec2(
			window->getScreenWidth() / 2.0f,
			window->getScreenHeight() / 2.0f)
	);

	spriteFont = new SpriteFont("Fonts/font.ttf", 64);
	spritebatch.init();
	hudSpriteBatch.init();
}

void MenuScreen::onExit() {}

void MenuScreen::update() {}

void MenuScreen::draw() {
	checkInput();
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint pLocation =
		program.getUniformLocation("P");
	glm::mat4 cameraMatrix = camera2d.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));
	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	spritebatch.begin();
	spritebatch.end();
	spritebatch.renderBatch();
	glBindTexture(GL_TEXTURE_2D, 0);
	program.unuse();
	window->swapBuffer();
	drawHUD();
}

void MenuScreen::drawHUD() {
	GLuint pLocation =
		program.getUniformLocation("P");
	glm::mat4 cameraMatrix = cameraHud.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));
	
	char buffer[256];
	hudSpriteBatch.begin();
	sprintf_s(buffer, "HOLA %d", 10);
	Color c;
	c.r = 255;
	c.g = 255;
	c.b = 255;
	c.a = 255;
	spriteFont->draw(hudSpriteBatch, buffer, glm::vec2(0, 0),
		glm::vec2(0.5), 0.0f, c);
	hudSpriteBatch.end();
	hudSpriteBatch.renderBatch();
}

void MenuScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		
	}
}


MenuScreen::~MenuScreen()
{
}
