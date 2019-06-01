#pragma once
#include "IGameScreen.h"
#include "SpriteBatch.h"
#include "Window.h"

class MenuScreen : public IGameScreen
{
private:
	Window* window = nullptr;
	SpriteBatch spritebatch;
public:
	MenuScreen(Window* _window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void draw() override;
	virtual void update() override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
	~MenuScreen();
};

