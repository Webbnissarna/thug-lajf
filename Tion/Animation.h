#pragma once

#include "SFML/Graphics.hpp"
#include "AnimationFrame.h"

class Animation : public sf::Drawable, public sf::Transformable {
public:
	void update(float dt);
	void addFrame(AnimationFrame* frame);
	void cleanup();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	float timeElapsed;
	unsigned int frameNbr = 0;
	std::vector<AnimationFrame*> frames;

	
};