#pragma once
#include <unordered_map>
#include <glm\glm.hpp>

class InputManager
{
	private:
		std::unordered_map<unsigned int, bool> keys;
		glm::vec2 mouseCoords;
public:
	InputManager();
	glm::vec2 getMouseCoords() const {
		return mouseCoords;
	}
	void setMouseCoords(float x, float y);
	void pressKey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool isKeyPressed(unsigned int keyCode);
	~InputManager();
};

