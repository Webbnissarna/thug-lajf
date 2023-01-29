#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "ObjectManager.h"
#include "ResourceManager.h"

#include "Background.h"

class Engine {
public:
	bool setup();
	bool run();
	void cleanup();

private:
	sf::RenderWindow* window;
	Renderer* renderer;
	ObjectManager* objMgr;
	ResourceManager* resMgr;

	sf::Clock clock;

	Background background;
};