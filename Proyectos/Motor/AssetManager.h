#pragma once

#include "GLTexture.h"
#include <string>
#include "TextureCache.h"

class AssetManager
{
private:
	static TextureCache textureCache;
public:
	static GLTexture getTexture(std::string texturePath);
};

