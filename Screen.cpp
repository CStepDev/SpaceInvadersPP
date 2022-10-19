#include "Screen.h"

void Screen::addPanel(std::shared_ptr<InputHandler> ih, std::unique_ptr<UIPanel> uip, ScreenManagerRemoteControl* smrc)
{
	ih->initialiseInputHandler(this, uip->getButtons(), &uip->m_View, smrc);

	// Using move() because otherwise the vector has a COPY, which is not allowed
	m_Panels.push_back(std::move(uip));

	// move() not required because shared pointer
	m_InputHandlers.push_back(ih);
}

void Screen::initialise()
{
	// Do nothing unless handled by a derived class
}

void Screen::handleInput(RenderWindow& window)
{
	Event event;
	auto itr = m_InputHandlers.begin();
	auto end = m_InputHandlers.end();

	while (window.pollEvent(event))
	{
		for (itr; itr != end; itr++)
		{
			(*itr)->handleInput(window, event);
		}
	}
}

void Screen::update(float fps)
{
	// Do nothing unless handled by a derived class
}

void Screen::draw(RenderWindow& window)
{
	auto itr = m_Panels.begin();
	auto end = m_Panels.end();

	for (itr; itr != end; itr++)
	{
		(*itr)->draw(window);
	}
}
