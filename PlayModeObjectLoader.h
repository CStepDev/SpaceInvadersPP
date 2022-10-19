#pragma once
#include "BlueprintObjectParser.h"
#include "GameObjectFactoryPlayMode.h"
#include "GameObject.h"
#include <vector>
#include <string>

class PlayModeObjectLoader
{
	private:
		BlueprintObjectParser m_BOP;
		GameObjectFactoryPlayMode m_GameObjectFactoryPlayMode;

	public:
		void loadGameObjectsForPlayMode(std::string pathToFile, std::vector<GameObject>& m_GameObjects);
};