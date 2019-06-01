#pragma once
#include "Window.h"
#include "InputManager.h"
#include <memory>

class Screenlist;
class IGameScreen;

class Game
{
public:
	Game();
	virtual ~Game();
	void run();
	void exit();
	virtual void onInit() = 0;
	virtual void addScreen() = 0;
	virtual void onExit() = 0;
	void onSDLEvent(SDL_Event& event);
protected:
	bool init();
	void update();
	void draw();
	bool initSystems();
	std::unique_ptr<Screenlist> screenList = nullptr;
	bool isRunning = false;
	Window window;
	InputManager inputManager;
	IGameScreen* currentScreen = nullptr;

};

