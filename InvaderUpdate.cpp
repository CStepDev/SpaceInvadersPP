#include "InvaderUpdateComponent.h"
#include "BulletSpawner.h"
#include "WorldState.h"
#include "SoundEngine.h"

void InvaderUpdateComponent::update(float fps)
{
	if (m_MovingRight)
	{
		m_TC->getLocation().x += m_Speed * fps;
	}
	else
	{
		m_TC->getLocation().x -= m_Speed * fps;
	}

	// Update the collider
	m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);

	// Update timer
	m_TimeSinceLastShot += fps;

	// Check if invader above player
	if ((m_TC->getLocation().x + (m_TC->getSize().x / 2)) >
		(m_PlayerTC->getLocation().x - m_AccuracyModifier) &&
		(m_TC->getLocation().x + (m_TC->getSize().x / 2)) <
		(m_PlayerTC->getLocation().x + (m_PlayerTC->getSize().x + m_AccuracyModifier)))
	{
		// Has the invader waited long enough since the last shot
		if (m_TimeSinceLastShot > m_TimeBetweenShots)
		{
			SoundEngine::playShoot();

			Vector2f spawnLocation;
			spawnLocation.x = m_TC->getLocation().x + m_TC->getSize().x / 2;
			spawnLocation.y = m_TC->getLocation().y + m_TC->getSize().y;

			m_BulletSpawner->spawnBullet(spawnLocation, false);

			srand(m_RandSeed);

			m_TimeBetweenShots = (float)(((rand() % 10)) + 1) / WorldState::WAVE_NUMBER;
			m_TimeSinceLastShot = 0;
		}
	}
}

void InvaderUpdateComponent::dropDownAndReverse()
{
	m_MovingRight = !m_MovingRight;

	m_TC->getLocation().y += m_TC->getSize().y;

	m_Speed += (WorldState::WAVE_NUMBER) + (WorldState::NUM_INVADERS_AT_START - WorldState::NUM_INVADERS) * m_SpeedModifier;
}

bool InvaderUpdateComponent::isMovingRight()
{
	return m_MovingRight;
}

void InvaderUpdateComponent::initialiseBulletSpawner(BulletSpawner* bulletSpawner, int randSeed)
{
	m_BulletSpawner = bulletSpawner;
	m_RandSeed = randSeed;
	srand(m_RandSeed);
	m_TimeBetweenShots = (float)(rand() % 15 + m_RandSeed);

	m_AccuracyModifier = (float)(rand() % 2);
	m_AccuracyModifier += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (10)));
}