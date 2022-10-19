#include "AnimatedGraphicsComponent.h"
#include "BitmapStore.h"

void AnimatedGraphicsComponent::setAnimationSettings(int numberOfFrames, float animationSpeed)
{
	currentFrame = 0;
	lastFrame = numberOfFrames - 1;
	timeSinceLastFrame = 0.0f;
	frameDuration = animationSpeed;
}

void AnimatedGraphicsComponent::updateAnimationFrame(float dt)
{
	timeSinceLastFrame += (1.0f * dt);

	if (timeSinceLastFrame >= frameDuration)
	{
		currentFrame++;

		if (currentFrame > lastFrame)
		{
			currentFrame = 0;
		}

		timeSinceLastFrame = 0.0f;
	}
}

void AnimatedGraphicsComponent::initialiseGraphics(std::string bitmapName, Vector2f objectSize)
{
	spriteVector.clear();

	int i = 0;

	while (i < lastFrame)
	{
		Sprite newSprite;

		BitmapStore::addBitmap("graphics/" + bitmapName + std::to_string(i) + ".png");

		newSprite.setTexture(BitmapStore::getBitmap("graphics/" + bitmapName + std::to_string(i) + ".png"));
		auto textureSize = newSprite.getTexture()->getSize();
		newSprite.setScale(float(objectSize.x) / textureSize.x, float(objectSize.y) / textureSize.y);

		spriteVector.push_back(newSprite);

		i++;
	}
}

void AnimatedGraphicsComponent::draw(RenderWindow& window, std::shared_ptr<TransformComponent> t)
{
	spriteVector[currentFrame].setPosition(t->getLocation());
	window.draw(spriteVector[currentFrame]);
}
