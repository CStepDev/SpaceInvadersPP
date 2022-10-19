#include "Button.h"

Button::Button(Vector2f position, Vector2f size, int red, int green, int blue, std::string text)
{
	m_Button.setPosition(position);
	m_Button.setFillColor(sf::Color(red, green, blue));
	m_Button.setSize(size);

	float textPaddingX = size.x / 10;
	float textPaddingY = size.y / 10;
	m_ButtonText.setCharacterSize(size.y * 0.7f);
	m_ButtonText.setString(text);
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_ButtonText.setFont(m_Font);
	m_ButtonText.setPosition(Vector2f((position.x + textPaddingX), (position.y + textPaddingY)));

	m_Collider = FloatRect(position, size);
	m_Text = text;
}

void Button::draw(RenderWindow& window)
{
	window.draw(m_Button);
	window.draw(m_ButtonText);
}