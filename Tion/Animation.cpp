#include "Animation.h"

#include "Locator.h"

void Animation::update(float dt)
{
	if (frames.at(frameNbr)->update(dt)) {
		frameNbr++;
		frameNbr = frameNbr % frames.size();
	}
}

void Animation::addFrame(AnimationFrame* frame)
{
	frames.push_back(frame);
}

void Animation::cleanup()
{
	for (AnimationFrame* frame : frames) {
		if (frame) {
			frame->cleanup();
			delete frame;
			frame = nullptr;
		}
	}
}



void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(*frames.at(frameNbr), states);
}
