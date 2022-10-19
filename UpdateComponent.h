#pragma once
#include "Component.h"

class UpdateComponent : public Component
{
	private:
		std::string m_Type = "update";
		bool m_Enabled = false;

	public:
		virtual void update(float fps) = 0;

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
			// To be filled by inheriting class
		}
};