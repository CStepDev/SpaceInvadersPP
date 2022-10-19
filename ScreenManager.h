#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "GameScreen.h"
#include "SelectScreen.h"
#include "ScreenManagerRemoteControl.h"
#include "LevelManager.h"
#include "BitmapStore.h"

using namespace sf;

class ScreenManager : public ScreenManagerRemoteControl
{
	private:
		std::map <std::string, std::unique_ptr<Screen>> m_Screens;
		LevelManager m_LevelManager;

	protected:
		std::string m_CurrentScreen = "Select";

	public:
		BitmapStore m_BS;

		ScreenManager(Vector2i res);
		void handleInput(RenderWindow& window);
		void update(float fps);
		void draw(RenderWindow& window);

		// Start of 'From ScreenManagerRemoteControl inferface'
		void ScreenManagerRemoteControl::SwitchScreens(std::string screenToSwitchTo)
		{
			m_CurrentScreen = "" + screenToSwitchTo;
			m_Screens[m_CurrentScreen]->initialise();
		}

		void ScreenManagerRemoteControl::loadLevelInPlayMode(std::string screenToLoad)
		{
			m_LevelManager.getGameObjects().clear();
			m_LevelManager.loadGameObjectsForPlayMode(screenToLoad);
			SwitchScreens("Game");
		}

		std::vector<GameObject>& ScreenManagerRemoteControl::getGameObjects()
		{
			return m_LevelManager.getGameObjects();
		}

		GameObjectSharer& shareGameObjectSharer()
		{
			return m_LevelManager;
		}

		 //End of 'From ScreenManagerRemoteControl interface'
};