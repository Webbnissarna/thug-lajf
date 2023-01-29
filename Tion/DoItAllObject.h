#pragma once

#include "Object.h"
#include "Animation.h"

class DoItAllObject : public Object {
public:
	DoItAllObject();
	DoItAllObject(sf::Vector2f position);
	DoItAllObject(float x, float y);

	// Inherited via Object
	virtual void update(float dt) override;
	virtual sf::Drawable* getDrawable() override;

	void setAnimation(Animation* animation);

	virtual void cleanup() override;
	virtual sf::Transformable* getTransformable() override;
	virtual void scale(sf::Vector2f scale) override;

private:
	Animation* animation;

	
};