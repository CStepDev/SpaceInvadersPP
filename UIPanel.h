#pragma once
//#include <SFML/Graphics.hpp>
#include "Button.h"

class UIPanel
{
	private:
		RectangleShape m_UIPanel;
		bool m_Hidden = false;
		std::vector<std::shared_ptr<Button>> m_Buttons;

	protected:
		float m_ButtonWidth = 0;
		float m_ButtonHeight = 0;
		float m_ButtonPadding = 0;

		Font m_Font;
		Text m_Text;

		void addButton(Vector2f position, Vector2f size, int red, int green, int blue, std::string label);

	public:
		View m_View;

		UIPanel(Vector2i res, Vector2f position, Vector2f size, int alpha, int red, int green, int blue);

		std::vector<std::shared_ptr<Button>> getButtons();
		virtual void draw(RenderWindow& window);
		void show();
		void hide();
};