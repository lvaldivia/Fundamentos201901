#include "GameScreen.h"


GameScreen::~GameScreen()
{
}

GameScreen::GameScreen(Window * _window) :window(_window)
{
	screenIndex = 2;
}

void GameScreen::build()
{
}

void GameScreen::destroy()
{
}

void GameScreen::onExit()
{
}

void GameScreen::onEntry()
{
}

void GameScreen::draw()
{
}

void GameScreen::update()
{
}

void GameScreen::initSystem()
{
}

int GameScreen::getNextScreen() const
{
	return 0;
}

int GameScreen::getPreviousScreen() const
{
	return 0;
}

void GameScreen::checkInput()
{
}
