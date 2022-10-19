#include "SelectUIPanel.h"
#include <iostream>

void SelectUIPanel::initialiseButtons()
{
	// Buttons are positioned relative to the top left corner of the UIPanel (m_View in UIPanel)
	addButton(Vector2f(m_ButtonPadding, m_ButtonPadding), Vector2f(m_ButtonWidth, m_ButtonHeight), 0, 255, 0, "Play");
	addButton(Vector2f(m_ButtonWidth + (m_ButtonPadding * 2), m_ButtonPadding), Vector2f(m_ButtonWidth, m_ButtonHeight), 255, 0, 0, "Quit");
}

// Calling the super-class constructor
SelectUIPanel::SelectUIPanel(Vector2i res) : UIPanel(res, Vector2f((res.x / 10) * 2, (res.y / 3)), Vector2f((res.x / 10) * 6, (res.y / 3)), 125, 255, 255, 255)
{
	m_ButtonWidth = float(res.x / 20);
	m_ButtonHeight = float(res.y / 20);
	m_ButtonPadding = float(res.x / 100);

	m_Text.setFillColor(Color(0, 255, 0, 255));
	m_Text.setString("SPACE INVADERS ++");

	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);

	m_Text.setPosition(Vector2f(m_ButtonPadding, m_ButtonHeight + (m_ButtonPadding * 2)));

	m_Text.setCharacterSize(140);

	initialiseButtons();
}

void SelectUIPanel::draw(RenderWindow& window)
{
	show();
	UIPanel::draw(window);
	window.draw(m_Text);
}