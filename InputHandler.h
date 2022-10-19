#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"

using namespace sf;

class Screen;

class InputHandler
{
	private:
		Screen* m_ParentScreen;
		std::vector<std::shared_ptr<Button>> m_Buttons;
		View* m_PointerToUIPanelView;
		ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;

	public:
		void initialiseInputHandler(Screen* parentScreen, std::vector<std::shared_ptr<Button>> buttons, View* pointerToUIView, ScreenManagerRemoteControl* sw);

		void handleInput(RenderWindow& window, Event& event);
		virtual void handleGamepad();
		virtual void handleKeyPressed(Event& event, RenderWindow& window);
		virtual void handleKeyReleased(Event& event, RenderWindow& window);
		virtual void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window);

		Screen* getParentScreen();
		View* getPointerToUIView();
		ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();
};