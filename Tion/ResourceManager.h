#pragma once

#include <map>

#include "SFML/Graphics/Texture.hpp"

enum EStatus {
	WENTSHIT = 0,
	OK = 1
};

struct Resource {
	std::string id;
	EStatus status;
};

class ResourceManager {
public:
	Resource loadTexture(std::string path);
	sf::Texture* getTexture(std::string id);

	void cleanup();

private:
	std::map<std::string, sf::Texture*> textures;
};