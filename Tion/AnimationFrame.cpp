#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(sf::Texture* text, sf::Vector2i texCoords, sf::Vector2i size, float dur)
{
	texture = text;
	sprite = new sf::Sprite(*texture, sf::IntRect(texCoords, size));
	duration = dur;
	timeElapsed = 0;
}

bool AnimationFrame::update(float dt)
{
	timeElapsed += dt;

	if (timeElapsed > duration) {
		timeElapsed = 0;
		return true;
	}
	
	return false;
}

void AnimationFrame::cleanup() {
	if (sprite) {
		delete sprite;
		sprite = nullptr;
	}
}

void AnimationFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*sprite, states);
}
