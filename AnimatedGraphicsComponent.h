#pragma once
#include "GraphicsComponent.h"

class AnimatedGraphicsComponent : public GraphicsComponent
{
private:
	std::string m_SpecificType = "animated";

	std::vector<Sprite> spriteVector;
	int currentFrame = 0;
	int lastFrame = 0;
	float timeSinceLastFrame = 0.0f;
	float frameDuration = 0.0f;

public:
	// From Component
	std::string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{
		// Uhhhhhhhhhhh... Stinky?
	}

	void setAnimationSettings(int numberOfFrames, float animationSpeed);

	void updateAnimationFrame(float dt);

	void initialiseGraphics(std::string bitmapName, Vector2f objectSize) override;

	void draw(RenderWindow& window, std::shared_ptr<TransformComponent> t) override;
};