#include "ObjectService.h"

void ObjectService::addObject(Object* object)
{
    objects.push_back(object);
}

std::vector<sf::Drawable*> ObjectService::getObjectRenders()
{
    auto drawables = std::vector<sf::Drawable*>();
    for (Object* obj : objects)
    {
        auto render = obj->getDrawable();
        if (render) {
            drawables.push_back(obj->getDrawable());
        }
    }
    return drawables;
}

void ObjectService::updateObjects(float dt)
{
    for (unsigned int i = 0; i < objects.size(); ++i) {
        objects.at(i)->update(dt);
    }
}

void ObjectService::cleanup() {
    for (int i = objects.size() - 1; i >= 0; --i) {
        if (objects[i]) {
            delete objects[i];
            objects[i] = nullptr;
        }
    }
}

void ObjectService::setScale(sf::Vector2f newScale)
{
    sf::Vector2f oldScale = scale;
    scale = newScale;
    
    for (Object* obj : objects) {
        auto transform = obj->getTransformable();
        auto currentScale = transform->getScale();
        transform->setScale(sf::Vector2f(currentScale.x / oldScale.x * scale.x, currentScale.y / oldScale.y * scale.y));
    }
}
