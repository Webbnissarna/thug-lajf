#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

using namespace sf;

class Renderer : sf::Drawable{
public:
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void addToQueue(sf::Drawable*);
	void addRangeToQueue(std::vector<sf::Drawable*>);
	void clearQueue();
private:
	std::vector<sf::Drawable*> drawables;
};