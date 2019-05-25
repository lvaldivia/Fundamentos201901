#pragma once
#include <string>
#include <vector>
#include "SpriteBatch.h"
using namespace std;

const int TILE_WIDTH = 64;

class Level
{
private:
	vector<string> levelData;
	int numHumans;
	void parseLevel();
public:
	glm::vec2 playerPosition;
	vector<glm::vec2> zombiesPosition;
	glm::vec2 getPlayerPosition()const {
		return playerPosition;
	}
	vector<glm::vec2> getZombiesPosition()const {
		return zombiesPosition;
	}
	Level(const string& fileName);
	void draw();
	SpriteBatch spritebatch;
	~Level();
};

