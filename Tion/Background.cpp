#include "Background.h"

Background::Background()
{
	background = nullptr;
	texture = nullptr;
}

Background::Background(sf::Sprite* sprite, sf::Texture* texture)
{
	this->texture = texture;
	this->background = sprite;
}

void Background::update(float dt)
{
}

sf::Drawable* Background::getDrawable()
{
	return background;
}

void Background::cleanup()
{
	if (texture) {
		delete texture;
		texture = nullptr;
	}
	if (background) {
		delete background;
		background = nullptr;
	}
}

sf::Transformable* Background::getTransformable()
{
	return background;
}

void Background::scale(sf::Vector2f scale)
{
	auto currentScale = background->getScale();
	background->setScale(sf::Vector2f(currentScale.x * scale.x, currentScale.y * scale.y));
}
