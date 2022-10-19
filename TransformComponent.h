#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Component;

class TransformComponent : public Component
{
	private:
		const std::string m_Type = "transform";
		Vector2f m_Location;
		float m_Width;
		float m_Height;

	public:
		TransformComponent(float width, float height, Vector2f location);

		Vector2f& getLocation();
		Vector2f getSize();

		// From Component
		std::string Component::getType()
		{
			return m_Type;
		}

		std::string Component::getSpecificType()
		{
			// Only one type of Transform so just return m_Type
			return m_Type;
		}

		void Component::enableComponent()
		{
			
		}

		void Component::disableComponent()
		{

		}

		bool Component::isEnabled()
		{
			return false;
		}

		void Component::start(GameObjectSharer* gos, GameObject* self)
		{
			// Stinky??
		}
};