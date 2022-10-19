#include "GameOverUIPanel.h"
#include "GameScreen.h"

bool GameScreen::m_GameOver;

void GameOverUIPanel::initialiseButtons()
{
	addButton(Vector2f(m_ButtonPadding, m_ButtonPadding), Vector2f(m_ButtonWidth, m_ButtonHeight), 0, 255, 0, "Play");
	addButton(Vector2f(m_ButtonWidth + (m_ButtonPadding * 2), m_ButtonPadding), Vector2f(m_ButtonWidth, m_ButtonHeight), 255, 0, 0, "Home");
}

GameOverUIPanel::GameOverUIPanel(Vector2i res) : UIPanel(res, Vector2f((res.x / 10) * 3, (res.y / 2)), Vector2f((res.x / 10) * 3, res.y / 6), 50, 255, 255, 255)
{
	m_ButtonWidth = res.x / 20;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setString("GAME OVER!");
	m_Text.setFillColor(Color(0, 255, 0, 255));
	m_Text.setPosition(Vector2f(m_ButtonPadding, (m_ButtonPadding * 2) + m_ButtonHeight));
	m_Text.setCharacterSize(60);

	initialiseButtons();
}

void GameOverUIPanel::draw(RenderWindow& window)
{
	if (GameScreen::m_GameOver)
	{
		show();
		UIPanel::draw(window);
		window.draw(m_Text);
	}
	else
	{
		hide();
	}
}