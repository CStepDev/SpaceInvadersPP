#pragma once
#include "GameObjectsBlueprint.h"
#include "GameObject.h"
#include <vector>

class GameObjectFactoryPlayMode
{
	public:
		void buildGameObject(GameObjectBlueprint& bp, std::vector<GameObject>& gameObjects);
};