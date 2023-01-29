#pragma once

#include "ObjectManager.h"

class ObjectService : public ObjectManager {
public:
	// Inherited via ObjectManager
	virtual void addObject(Object*) override;
	virtual std::vector<sf::Drawable*> getObjectRenders() override;
	virtual void updateObjects(float dt) override;
	virtual void cleanup() override;
	// Inherited via ObjectManager
	virtual void setScale(sf::Vector2f newScale) override;
private:
	std::vector<Object*> objects;

	
};