#pragma once
#include "Component.h"
#include <iostream>

class ColliderComponent : public Component
{
	private:
		std::string m_Type = "collider";
		bool m_Enabled = false;

	public:
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
			// Fulfilled by inheriting class
		}
};