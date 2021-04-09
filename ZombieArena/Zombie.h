#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	//how fast is each zombie
	const float BLOATER_SPEED = 40.f;
	const float CHASER_SPEED = 80.f;
	const float CRAWLER_SPEED = 20.f;

	//How touch is each zombie type
	const float BLOATER_HEALTH = 5.f;
	const float CHASER_HEALTH = 1.f;
	const float CRAWLER_HEALTH = 3.f;

	//MAKE EACH ZOMBIE VARY ITS SPEED SLIGHTLY
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	//where is the zombie
	Vector2f m_Position;

	//a sprite of the zombie
	Sprite m_Sprite;

	//how fast can this one run/crawl
	float m_Speed;

	//how much health does it got
	float m_Health;

	//is it still alive ???
	bool m_Alive;
public:
	//handle when a boolet his the zombie
	bool hit();

	//find out if the zombie is still alive
	bool isAlive();

	//spawn a zombie
	void spawn(float startX,float startY, int type, int seed);

	//position of the zombie in the game world
	FloatRect getPosition();

	//get a copy of the sprite of the zombie
	Sprite getSprite();

	//update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);
};

