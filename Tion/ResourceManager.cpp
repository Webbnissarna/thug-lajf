#include "ResourceManager.h"

#include "Logger.h"

Resource ResourceManager::loadTexture(std::string path)
{
	Resource res = Resource();
	res.status = WENTSHIT;

	const auto cachedTexture = getTexture(path);
	if (cachedTexture != nullptr) {
		res.status = OK;
		res.id = path;

		Logger::Success("Cache hit with texture " + path);

		return res;
	}

	Logger::Print("Cache miss with texture " + path);

	sf::Texture* texture = new sf::Texture();
	const bool status = texture->loadFromFile(path);
	
	if (status) {
		res.status = OK;
		res.id = path;

		textures.insert({ path, texture });

		Logger::Success("Loaded texture " + path);

		return res;
	}
	else {
		Logger::Error("Could not load texture " + path);
		return res;
	}
	
}

sf::Texture* ResourceManager::getTexture(std::string id)
{
	if (textures.contains(id)) {
		sf::Texture* text = textures[id];
		return text;
	}
	return nullptr;
}

void ResourceManager::cleanup()
{
	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (it->second) {
			delete it->second;
			it->second = nullptr;
		}
	}
}
