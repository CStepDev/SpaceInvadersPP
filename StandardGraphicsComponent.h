#pragma once
//#include "Component.h"
#include "GraphicsComponent.h"

class Component;

class StandardGraphicsComponent : public GraphicsComponent
{
	private:
		std::string m_SpecificType = "standard";
		Sprite m_Sprite;

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

		// From GraphicsComponent
		void initialiseGraphics(std::string bitmapName, Vector2f objectSize) override;

		void draw(RenderWindow& window, std::shared_ptr<TransformComponent>t) override;
};