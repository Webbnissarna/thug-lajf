#pragma once

#include "ObjectManager.h"

class NullObjectService : public ObjectManager {
	// Inherited via ObjectManager
	virtual void addObject(Object*) override;
	virtual std::vector < sf::Drawable* > getObjectRenders() override;
	virtual void updateObjects(float dt) override;
	virtual void cleanup() override;
};