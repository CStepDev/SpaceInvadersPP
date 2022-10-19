#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "GameObjectSharer.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class GraphicsComponent : public Component
{
	private:
		std::string m_Type = "graphics";
		bool m_Enabled = false;

	public:
		virtual void initialiseGraphics(std::string bitmapName, Vector2f objectSize) = 0;

		virtual void draw(RenderWindow& window, std::shared_ptr<TransformComponent> t) = 0;

		// From Component Interface
		std::string Component::getType()
		{
			return m_Type;
		}

		void Component::enableComponent()
		{
			m_Enabled = true;
		}

		void Component::disableComponent()
		{
			m_Enabled = false;
		}

		bool Component::isEnabled()
		{
			return m_Enabled;
		}

		void Component::start(GameObjectSharer* gos, GameObject* self)
		{
			// Fullfilled by inheriting class
		}
};