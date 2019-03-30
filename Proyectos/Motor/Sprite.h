#pragma once

class Sprite {
private:
	float x;
	float y;
	int width;
	int height;
public:
	Sprite();
	~Sprite();
	void init(float x, float y, int width, int height);
	void draw();
};
