#pragma once

#include "Object.h"

#include "SFML/Graphics.hpp"

class Background : public Object {
public:
	Background();
	Background(sf::Sprite* drawable, sf::Texture* texture);
	// Inherited via Object
	virtual void update(float dt) override;
	virtual sf::Drawable* getDrawable() override;

	virtual void cleanup() override;
	virtual sf::Transformable* getTransformable() override;
	virtual void scale(sf::Vector2f scale) override;

private:
	sf::Texture* texture;
	sf::Sprite* background;

	
};