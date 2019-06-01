#pragma once
#include <algorithm>
#include "Game.h"
#include "GameScreen.h"
#include "MenuScreen.h"

class App : public Game
{
public:
	App();
	~App();
	virtual void onInit() override;
	virtual void onExit() override;
	virtual void addScreen() override;
private:
	std::unique_ptr<GameScreen>
		gameScreen = nullptr;
	std::unique_ptr<MenuScreen>
		menuScreen = nullptr;
};

