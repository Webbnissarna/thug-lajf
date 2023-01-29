#pragma once

#include "ObjectManager.h"
#include "ResourceManager.h"

#include "SFML/Graphics.hpp"

class Locator {
public:
	static ObjectManager* getObjectManager();
	static void provideObjectManager(ObjectManager* mgr);

	static ResourceManager* getResourceManager();
	static void provideResourceManager(ResourceManager* mgr);

	static sf::Vector2f getScale();
	static void provideScale(sf::Vector2f scale);
private:
	static ObjectManager* objMgr;
	static ResourceManager* resMgr;

	static sf::Vector2f scale;
};