#include "DoItAllObject.h"

DoItAllObject::DoItAllObject() {
    animation = nullptr;
}
DoItAllObject::DoItAllObject(sf::Vector2f pos) {
    animation = nullptr;
    initialPosition = pos;
}

DoItAllObject::DoItAllObject(float x, float y) {
    animation = nullptr;
    initialPosition = sf::Vector2f(x, y);
}


void DoItAllObject::update(float dt)
{
    //printf("updating object %f...\n", dt);
    animation->update(dt);
}

sf::Drawable* DoItAllObject::getDrawable()
{
    return animation;
}

void DoItAllObject::setAnimation(Animation* anim)
{
    animation = anim;
    animation->setPosition(initialPosition);
}

void DoItAllObject::cleanup()
{
    if (animation) {
        animation->cleanup();
        delete animation;
        animation = nullptr;
    }
}

sf::Transformable* DoItAllObject::getTransformable()
{
    return animation;
}

void DoItAllObject::scale(sf::Vector2f scale)
{
    auto currentScale = animation->getScale();
    animation->setScale(sf::Vector2f(currentScale.x * scale.x, currentScale.y * scale.y));
}
