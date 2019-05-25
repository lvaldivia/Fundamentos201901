#include "Level.h"
#include <fstream>
#include "ResourceManager.h"
#include "Error.h"


Level::Level(const string &fileName)
{
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		fatalError("no abre el archivo " + fileName);
	}

	string tmp;
	file >> tmp >> numHumans;
	while (getline(file, tmp)) {
		levelData.push_back(tmp);
	}
	parseLevel();
}

void Level::parseLevel() {
	spritebatch.init();
	spritebatch.begin();
	glm::uvec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	for (size_t i = 0; i < levelData.size(); i++)
	{
		for (size_t j = 0; j < levelData[i].size(); j++)
		{
			char tile = levelData[i][j];
			glm::vec4 destRect
				(i*TILE_WIDTH, j*TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
			switch (tile)
			{
			case 'R':
			case 'B':
				spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Textures/red_bricks.png").id,
					0.0f, color
				);
				break;
			case 'G':
				break;
			case 'L':
				break;
			case '@':
				break;
			case 'Z':
				break;
			case '.':
				break;
			default:
				break;
			}
		}
	}
	spritebatch.end();
}

void Level::draw() {
	spritebatch.renderBatch();
}


Level::~Level()
{
}
