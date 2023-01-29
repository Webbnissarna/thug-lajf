#include "NullObjectService.h"

void NullObjectService::addObject(Object*)
{
}

std::vector<sf::Drawable*> NullObjectService::getObjectRenders()
{
    return std::vector<sf::Drawable*>();
}

void NullObjectService::updateObjects(float dt)
{
}

void NullObjectService::cleanup()
{
}
