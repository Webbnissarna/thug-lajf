#include "Engine.h"

#include "ObjectService.h"

//Test
#include "DoItAllObject.h"
#include "AnimationFrame.h"
#include "Animation.h"

#include "Locator.h"

// Temporary object factory
void createWorker(unsigned int offset, ObjectManager* objMgr, ResourceManager* resMgr) {
	Animation* animWorkerFrontGatherAbove = new Animation();
	Resource workerRes = resMgr->loadTexture("../resources/worker.png");

	sf::Texture* frontGatherAboveTex = resMgr->getTexture(workerRes.id);
	sf::Vector2i animSpriteSize = sf::Vector2i(40, 40);

	AnimationFrame* gatherAboveFrame01 = new AnimationFrame(frontGatherAboveTex, sf::Vector2i(0, animSpriteSize.y * offset), animSpriteSize, 0.4f);
	AnimationFrame* gatherAboveFrame02 = new AnimationFrame(frontGatherAboveTex, sf::Vector2i(animSpriteSize.x, animSpriteSize.y * offset), animSpriteSize, 0.4f);

	animWorkerFrontGatherAbove->addFrame(gatherAboveFrame01);
	animWorkerFrontGatherAbove->addFrame(gatherAboveFrame02);

	DoItAllObject* worker = new DoItAllObject(400, 400 + animSpriteSize.y * offset * 2);
	worker->setAnimation(animWorkerFrontGatherAbove);
	worker->scale(sf::Vector2f(2, 2));
	objMgr->addObject(worker);
}


bool Engine::setup() {
	auto modes = sf::VideoMode::getFullscreenModes();
	window = new sf::RenderWindow(modes.at(1), "OTUA", sf::Style::Fullscreen);
	renderer = new Renderer();
	objMgr = new ObjectService();
	resMgr = new ResourceManager();
	clock = sf::Clock();

	// Temp
	Resource backgroundRes = resMgr->loadTexture("../resources/village.png");
	sf::Texture* backgroundTex = resMgr->getTexture(backgroundRes.id);
	sf::Sprite* backgroundSprite = new sf::Sprite(*backgroundTex);
	background = Background(backgroundSprite, backgroundTex);

	// Background scaling
	auto size = window->getSize();
	auto scale = sf::Vector2f(size.x / backgroundSprite->getLocalBounds().width, size.y / backgroundSprite->getLocalBounds().height);
	
	backgroundSprite->setScale(scale);
	
	Locator::provideScale(scale);

	// Building
	Animation* anim = new Animation();
	Resource res = resMgr->loadTexture("../resources/cottage.png");
	if (res.status = WENTSHIT)
		return false;
	sf::Texture* text = resMgr->getTexture(res.id);
	sf::Vector2i animationSpriteSize = sf::Vector2i(349,353);
	AnimationFrame* frame01 = new AnimationFrame(text, sf::Vector2i(), animationSpriteSize, 2);
	AnimationFrame* frame02 = new AnimationFrame(text, sf::Vector2i(animationSpriteSize.x * 1, 0), animationSpriteSize, 2);
	AnimationFrame* frame03 = new AnimationFrame(text, sf::Vector2i(animationSpriteSize.x * 2, 0), animationSpriteSize, 2);
	anim->addFrame(frame01);
	anim->addFrame(frame02);
	anim->addFrame(frame03);

	DoItAllObject* obj = new DoItAllObject(size.x/2, size.y/2);
	obj->setAnimation(anim);

	objMgr->addObject(obj);

	// unit
	createWorker(0, objMgr, resMgr);
	createWorker(1, objMgr, resMgr);
	createWorker(2, objMgr, resMgr);
	createWorker(3, objMgr, resMgr);
	createWorker(4, objMgr, resMgr);
	createWorker(5, objMgr, resMgr);
	createWorker(6, objMgr, resMgr);
	createWorker(7, objMgr, resMgr);

	return true;
}



bool Engine::run() {
	while (window->isOpen()) {
		float dt = clock.restart().asSeconds();

		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window->close();
				}
			}
		}

		objMgr->updateObjects(dt);

		window->clear(sf::Color(20, 200, 200, 255));

		renderer->addRangeToQueue(objMgr->getObjectRenders());

		if (background.getDrawable()) {
			window->draw(*background.getDrawable());
		}

		// update systems?
		renderer->draw(*window, sf::RenderStates::Default);
		renderer->clearQueue();

		window->display();
	}
	return true;
}

void Engine::cleanup() {
	if (window) {
		delete window;
		window = nullptr;
	}
	if (renderer) {
		renderer->clearQueue();
		delete renderer;
		renderer = nullptr;
	}
	if (objMgr) {
		objMgr->cleanup();
		delete objMgr;
		objMgr = nullptr;
	}
	if (resMgr) {
		resMgr->cleanup();
		delete resMgr;
		resMgr = nullptr;
	}
}