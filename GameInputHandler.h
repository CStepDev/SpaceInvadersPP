#pragma once
#include "InputHandler.h"
#include "PlayerUpdateComponent.h"
#include "TransformComponent.h"

class GameScreen;

class GameInputHandler : public InputHandler
{
	private:
		std::shared_ptr<PlayerUpdateComponent> m_PUC;
		std::shared_ptr<TransformComponent> m_PTC;

		bool m_ControllerButtonPressed = false;

	public:
		void initialise();
		void handleKeyPressed(Event& event, RenderWindow& window) override;
		void handleKeyReleased(Event& event, RenderWindow& window) override;
		void handleGamepad() override;
};