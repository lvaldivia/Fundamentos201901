#include "App.h"
#include "ScreenList.h"


App::App()
{
}

void App::onInit() {

}

void App::onExit() {

}

void App::addScreen() {
	menuScreen = std::make_unique<MenuScreen>
		(&window);
	/*gameScreen = std::make_unique<GameScreen>
		(&window);*/
	screenList->addScreen(menuScreen.get());
	//screenList->addScreen(gameScreen.get());
	screenList->setScreen(menuScreen->getIndex());
}


App::~App()
{
}
