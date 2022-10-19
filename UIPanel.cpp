#include "UIPanel.h"

UIPanel::UIPanel(Vector2i res, Vector2f position, Vector2f size, int alpha, int red, int green, int blue)
{
	m_UIPanel.setFillColor(Color(red, green, blue, alpha));

	// Size of the UIPanel (width, height)
	m_UIPanel.setSize(size);

	// Size of the View instance (width, height)
	m_View.setSize(size);

	// Center the View instance using size
	m_View.setCenter(size.x / 2, size.y / 2);

	// Where in the window is the view positioned?
	float viewportStartX = 1.0f / (res.x / position.x);
	float viewportStartY = 1.0f / (res.y / position.y);
	float viewportSizeX = 1.0f / (res.x / size.x);
	float viewportSizeY = 1.0f / (res.y / size.y);

	m_View.setViewport(FloatRect(viewportStartX, viewportStartY, viewportSizeX, viewportSizeY));
}

std::vector<std::shared_ptr<Button>> UIPanel::getButtons()
{
	return m_Buttons;
}

void UIPanel::addButton(Vector2f position, Vector2f size, int red, int green, int blue, std::string label)
{
	// Create a shared pointer to a new Button instance and add it to m_Buttons
	m_Buttons.push_back(std::make_shared<Button>(position, size, red, green, blue, label));
}

void UIPanel::draw(RenderWindow& window)
{
	window.setView(m_View);

	if (!m_Hidden)
	{
		window.draw(m_UIPanel);

		for (auto it = m_Buttons.begin(); it != m_Buttons.end(); it++)
		{
			(*it)->draw(window);
		}
	}
}

void UIPanel::show()
{
	m_Hidden = false;
}

void UIPanel::hide()
{
	m_Hidden = true;
}