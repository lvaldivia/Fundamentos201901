#include "TextureCache.h"
#include "ImageLoader.h"

TextureCache::TextureCache()
{

}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	/*std::map<std::string, GLTexture>::iterator tci =
		textureMap.find(texturePath);*/
	auto tci = textureMap.find(texturePath);
	if (tci == textureMap.end()) {
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		/*std::pair<std::string, GLTexture> newPair(texturePath, texture);
		textureMap.insert(newPair);*/
		textureMap[texturePath] = texture;
		return texture;
	}

	return tci->second;


}

TextureCache::~TextureCache()
{
}
