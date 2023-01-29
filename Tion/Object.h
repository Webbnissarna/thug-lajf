#pragma once

#include "SFML/Graphics.hpp"

class Object {
public:
	virtual void update(float dt) = 0;
	virtual void cleanup() = 0;
	virtual sf::Drawable* getDrawable() = 0;
	virtual sf::Transformable* getTransformable() = 0;
	virtual void scale(sf::Vector2f scale) = 0;
protected:
	sf::Vector2f initialPosition;
};