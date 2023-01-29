#pragma once

#include <vector>
#include "Object.h"

class ObjectManager {
public:
	virtual ~ObjectManager() {};
	virtual void setScale(sf::Vector2f newScale) = 0;
	virtual void addObject(Object*) = 0;
	virtual std::vector<sf::Drawable*> getObjectRenders() = 0;
	virtual void updateObjects(float dt) = 0;
	virtual void cleanup() = 0;

protected:
	sf::Vector2f scale;
};