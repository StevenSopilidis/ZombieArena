#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

void Zombie::spawn(float startX, float startY, int type, int seed)
{
	//ditermine the type of zombie
	switch (type)
	{
	case 0:
		//Bloater
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bloater.png"));
		m_Speed = BLOATER_SPEED;
		m_Health = BLOATER_HEALTH;
	case 1:
		//chaser
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
		m_Speed = CHASER_SPEED;
		m_Health = CHASER_HEALTH;
	case 2:
		//crawler
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/crawler.png"));
		m_Speed = CRAWLER_HEALTH;
		m_Health = CRAWLER_HEALTH;
	default:
		//defaults to a crawleer
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
		m_Speed = CHASER_SPEED;
		m_Health = CHASER_HEALTH;
	}

	//modify the zombie's speed so every zombie 
	//is unique
	srand((int)time(0) * seed);

	//modify somewhere between 80 - 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;

	//express the modifier as a fraction of one
	//and modify the zombies speed
	modifier /= 100;
	m_Speed *= modifier;

	//initialize zombies positon
	m_Position.x = startX;
	m_Position.y = startY;

	//Set the zombies origin to the center of the Sprite
	m_Sprite.setOrigin(25, 25);

	//set the position of the zombie sprite
	m_Sprite.setPosition(m_Position);
}

bool Zombie::hit()
{
	m_Health--;

	if (m_Health < 0)
	{
		//the zombie is dead
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));

		return true;
	}

	//injured zombie but not dead yet
	return false;
}

bool Zombie::isAlive()
{
	return m_Alive;
}

FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Zombie::getSprite()
{
	return m_Sprite;
}

void Zombie::update(float elapsedTime, Vector2f playerPosition)
{
	float playerX = playerPosition.x;
	float playerY = playerPosition.y;

	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x + m_Speed * elapsedTime;
	}
	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y + m_Speed * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x - m_Speed * elapsedTime;
	}
	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y - m_Speed * elapsedTime;
	}

	//move the sprite
	m_Sprite.setPosition(m_Position);

	//set the zombie's sprite angle se it will face the player
	float angle = (atan2(playerY - m_Position.y, playerX - m_Position.y) * 180) / 3.341;

	m_Sprite.setRotation(angle);
}