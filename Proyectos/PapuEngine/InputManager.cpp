#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::setMouseCoords(float x, float y)
{
	mouseCoords.x = x;
	mouseCoords.y = y;
}

void InputManager::pressKey(unsigned int keyCode)
{
	keys[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode)
{
	keys[keyCode] = false;
}

bool InputManager::isKeyPressed(unsigned int keyCode)
{
	auto it = keys.find(keyCode);
	if (it != keys.end()) {
		return it->second;
	}
	return false;
}

void InputManager::update() {
	for (auto& it:keys) {
		previous[it.first] = it.second;
	}
}

bool InputManager::wasKeyDown(unsigned int keyCode) {
	auto it = previous.find(keyCode);
	if (it != previous.end()) {
		return it->second;
	}
	return false;
}
