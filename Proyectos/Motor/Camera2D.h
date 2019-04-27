#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Camera2D
{
private:
	glm::vec2 position;
	float scale;
	int screenWidth;
	int screenHeight;
	bool newsUpdateMatrix;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
public:
	void update();
	void init(int _screenWidth, int _screenHeight);
	glm::vec2 getPosition() { return position; }
	void setPosition(const glm::vec2& newPosition) {
		position = newPosition;
		newsUpdateMatrix = true;
	}
	void setScale(float newScale) {
		scale = newScale;
		newsUpdateMatrix = true;
	}

	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}
	Camera2D();
	~Camera2D();

};

