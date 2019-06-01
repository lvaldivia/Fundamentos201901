#pragma once
#include <vector>
class Game;
class IGameScreen;

class ScreenList
{
public:
	ScreenList(Game* _game);
	~ScreenList();
	IGameScreen* moveNext();
	IGameScreen* movePreviuos();
	void setScreen(int nextScreen);
	void addScreen(IGameScreen* newScreen);
	void destroy();
	IGameScreen* getCurrent();
protected:
	std::vector<IGameScreen*> screens;
	Game* game;
	int currentIndex = 1;
};

