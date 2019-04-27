#include "AssetManager.h"

TextureCache AssetManager::textureCache;

GLTexture AssetManager::getTexture(std::string texturePath) {
	return textureCache.getTexture(texturePath);
}

