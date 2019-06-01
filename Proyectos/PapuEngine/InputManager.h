#pragma once
#pragma once
#include <glm\glm.hpp>
#include <unordered_map>

class InputManager
{
private:
	std::unordered_map<unsigned int, bool> keys;
	std::unordered_map<unsigned int, bool> previous;
	bool wasKeyDown(unsigned int);
	glm::vec2 mouseCoords;
public:
	InputManager();
	~InputManager();
	glm::vec2 getMouseCoords()const {
		return mouseCoords;
	}
	void update();
	void setMouseCoords(float x, float y);
	void pressKey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool isKeyPressed(unsigned int keyCode);
};

