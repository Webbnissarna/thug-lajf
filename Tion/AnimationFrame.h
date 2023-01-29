#pragma once

#include "SFML/Graphics.hpp"

class AnimationFrame : public sf::Drawable {
public:

	AnimationFrame(sf::Texture* text, sf::Vector2i texCoords, sf::Vector2i size, float duration);
	bool update(float dt);
	void cleanup();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Texture* texture;
	sf::Sprite* sprite;
	
	float duration;
	float timeElapsed;
};