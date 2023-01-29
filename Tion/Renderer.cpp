#include "Renderer.h"

void Renderer::draw(RenderTarget& target, RenderStates states) const
{
	for (int i = 0; i < drawables.size(); ++i) {
		target.draw(*drawables[i], states);
	}
}

void Renderer::addToQueue(sf::Drawable* drawable) {
	drawables.push_back(drawable);
}

void Renderer::addRangeToQueue(std::vector<sf::Drawable*> range)
{
	drawables.insert(drawables.end(), range.begin(), range.end());
}

void Renderer::clearQueue() {
	drawables.clear();
}