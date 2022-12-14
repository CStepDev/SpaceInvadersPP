#pragma once
#include "Screen.h"
#include "PhysicsEnginePlayMode.h"
#include "GameInputHandler.h"
#include "GameOverInputHandler.h"
#include "BulletSpawner.h"

class GameScreen : public Screen, public BulletSpawner
{
	private:
		ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
		std::shared_ptr<GameInputHandler> m_GIH;
		PhysicsEnginePlayMode m_PhysicsEnginePlayMode;

		int m_NumberInvadersInWorldFile = 0;

		std::vector<int> m_BulletObjectLocations;
		int m_NextBullet = 0;
		bool m_WaitingToSpawnBulletForPlayer = false;
		bool m_WaitingToSpawnBulletForInvader = false;
		sf::Vector2f m_PlayerBulletSpawnLocation;
		sf::Vector2f m_InvaderBulletSpawnLocation;

		sf::Clock m_BulletClock;

		Texture m_BackgroundTexture;
		Sprite m_BackgroundSprite;

	public:
		static bool m_GameOver;

		GameScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

		void initialise() override;
		void update(float fps) override;
		void draw(RenderWindow& window) override;

		BulletSpawner* getBulletSpawner();

		// FROM BULLETSPAWNER INTERFACE
		void BulletSpawner::spawnBullet(sf::Vector2f spawnLocation, bool forPlayer)
		{
			if (forPlayer)
			{
				sf::Time elapsedTime = m_BulletClock.getElapsedTime();

				if (elapsedTime.asMilliseconds() > 500)
				{
					m_PlayerBulletSpawnLocation.x = spawnLocation.x;
					m_PlayerBulletSpawnLocation.y = spawnLocation.y;
					m_WaitingToSpawnBulletForPlayer = true;
					m_BulletClock.restart();
				}
			}
			else
			{
				m_InvaderBulletSpawnLocation.x = spawnLocation.x;
				m_InvaderBulletSpawnLocation.y = spawnLocation.y;
				m_WaitingToSpawnBulletForInvader = true;
			}
		}
};