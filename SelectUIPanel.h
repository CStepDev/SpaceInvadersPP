#pragma once
#include "UIPanel.h"

class SelectUIPanel : public UIPanel
{
	private:
		void initialiseButtons();

	public:
		SelectUIPanel(Vector2i res);
		void draw(RenderWindow& window) override;
};