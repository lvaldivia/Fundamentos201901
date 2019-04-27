#pragma once
#include <map>
#include "GLTexture.h"

class TextureCache
{
private:
	std::map<std::string, GLTexture> textureMap;
public:
	TextureCache();
	GLTexture getTexture(std::string texturePath);
	~TextureCache();
};

