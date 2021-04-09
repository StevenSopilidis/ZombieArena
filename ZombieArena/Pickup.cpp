#include "Pickup.h"
#include "TextureHolder.h"

Pickup::Pickup(int type)
{
	m_Type = type;
	
	//associate the pickup with the current texture
	if (m_Type == 1)
	{
		//health pickup
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/health_pickup.png"));
		m_Value = HEALTH_START_VALUE;
	}
	else {
		//ammo pickup
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/ammo_pickup.png"));
		m_Value = AMMO_START_VALUE;
	}
		
	m_Sprite.setOrigin(25, 25);

	m_SecondsToLive = START_SECONDS_TO_LIVE;
	m_SecondsToWait = START_WAIT_TIME;
}

void Pickup::setArena(IntRect arena)
{
	m_Arena.left = arena.left + 50;
	m_Arena.width = arena.width - 50;
	m_Arena.top = arena.top + 50;
	m_Arena.height = arena.height - 50;

	spawn();
}

void Pickup::spawn()
{
	//Spawn the pickup at a random location
	srand((int)time(0) / m_Type);
	int x = (rand() % m_Arena.width);

	srand((int)time(0) * m_Type);
	int y =  (rand() % m_Arena.height);

	m_SecondsSinceSpawn = 0;
	m_Spawned = true;
	m_Sprite.setPosition(x, y);
}

FloatRect Pickup::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

bool Pickup::isSpawned()
{
	return m_Spawned;
}

Sprite Pickup::getSprite()
{
	return m_Sprite;
}

int Pickup::gotIt()
{
	m_Spawned = false;
	m_SecondsSinceDeSpawn= 0;

	return m_Value;
}

void Pickup::update(float elapsedTime)
{
	if (m_Spawned)
	{
		m_SecondsSinceSpawn += elapsedTime;
	}
	else {
		m_SecondsSinceDeSpawn += elapsedTime;
	}

	//do we need to hide the pickup
	if (m_SecondsSinceSpawn > m_SecondsToLive && m_Spawned)
	{
		m_Spawned = false;
		m_SecondsSinceDeSpawn = 0;
	}

	//do we need to spawn the pickup
	if (m_SecondsSinceDeSpawn < m_SecondsToWait && !m_Spawned)
	{
		spawn();
	}
}

void Pickup::upgrade()
{
	if (m_Type == 1)
	{
		m_Value += (HEALTH_START_VALUE * 0.5);
	}
	else {
		m_Value += (AMMO_START_VALUE * 0.5);
	}

	///make pickups spawn more frequently and last longer
	m_SecondsToLive += (START_SECONDS_TO_LIVE / 10);
	m_SecondsToWait += (START_WAIT_TIME / 10);

}