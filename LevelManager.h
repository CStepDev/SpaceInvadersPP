#pragma once
#include "GameObject.h"
#include "GameObjectSharer.h"
#include <vector>
#include <string>

class LevelManager : public GameObjectSharer
{
	private:
		std::vector<GameObject> m_GameObjects;

		const std::string WORLD_FOLDER = "world";
		const std::string SLASH = "/";

		void runStartPhase();
		void activateAllGameObjects();

	public:
		std::vector<GameObject>& getGameObjects();
		void loadGameObjectsForPlayMode(std::string screenToLoad);

		// From GameObjectSharer Interface
		std::vector<GameObject>& GameObjectSharer::getGameObjectsWithGOS()
		{
			return m_GameObjects;
		}

		GameObject& GameObjectSharer::findFirstObjectWithTag(std::string tag)
		{
			auto it = m_GameObjects.begin();
			auto end = m_GameObjects.end();

			for (it; it != end; it++)
			{
				if ((*it).getTag() == tag)
				{
					return (*it);
				}
			}

			#ifndef debuggingErrors
				std::cout << "LevelManager.h findFirstGameObjectWithTag() - TAG NOT FOUND ERROR. Received tag: " << tag << std::endl;
			#endif // !debuggingErrors

			return m_GameObjects[0];
		}
};