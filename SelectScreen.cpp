#include "SelectScreen.h"
#include "SelectUIPanel.h"
#include "SelectInputHandler.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res)
{
	auto suip = std::make_unique<SelectUIPanel>(res);
	auto sih = std::make_shared<SelectInputHandler>();
	addPanel(sih, std::move(suip), smrc);
	m_ScreenManagerRemoteControl = smrc;

	m_BackgroundTexture.loadFromFile("graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	auto texSize = m_BackgroundSprite.getTexture()->getSize();
	m_BackgroundSprite.setScale(float(m_View.getSize().x / texSize.x), float(m_View.getSize().y / texSize.y));
}

void SelectScreen::draw(RenderWindow& window)
{
	// Change to this screen's view to draw
	window.setView(m_View);
	window.draw(m_BackgroundSprite);

	// Draw the UIPanel view(s)
	Screen::draw(window);
}