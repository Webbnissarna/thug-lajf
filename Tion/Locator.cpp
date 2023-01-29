#include "Locator.h"

ObjectManager* Locator::objMgr = nullptr;
ResourceManager* Locator::resMgr = nullptr;
sf::Vector2f Locator::scale = sf::Vector2f(1, 1);

ObjectManager* Locator::getObjectManager()
{
    return objMgr;
}

void Locator::provideObjectManager(ObjectManager* mgr)
{
    objMgr = mgr;
}

ResourceManager* Locator::getResourceManager()
{
    return resMgr;
}

void Locator::provideResourceManager(ResourceManager* mgr)
{
    resMgr = mgr;
}

sf::Vector2f Locator::getScale()
{
    return scale;
}

void Locator::provideScale(sf::Vector2f newScale)
{
    // Should objects subscribe to changes in scale? Or is it a non-issue?
    scale = newScale;
    if (objMgr) {
        objMgr->setScale(scale);
    }
}
