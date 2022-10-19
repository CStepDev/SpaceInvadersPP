#pragma once
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"

class InputHandler;

class Screen
{
	private:
		std::vector<std::shared_ptr<InputHandler>> m_InputHandlers;
		std::vector<std::unique_ptr<UIPanel>> m_Panels;

	protected:
		void addPanel(std::shared_ptr<InputHandler> ih, std::unique_ptr<UIPanel> uip, ScreenManagerRemoteControl* smrc);

	public:
		virtual void initialise();
		virtual void handleInput(RenderWindow& window);
		virtual void update(float fps);
		virtual void draw(RenderWindow& window);

		View m_View;
};