#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pickup
{
private:
	//starting values for pickups
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	//how much time before another pickup spawns
	const int START_WAIT_TIME = 10;
	//how much time untill pickup disapears
	const int START_SECONDS_TO_LIVE = 5;

	Sprite m_Sprite;

	IntRect m_Arena;

	//how much is this pickup worth
	int m_Value;

	//what type of pickup
	//1 for health, 2 for ammo
	int m_Type;

	//handle the spawning and disapearing
	bool m_Spawned;
	float m_SecondsSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;
public:
	Pickup(int type);

	//prepare the new pickup
	void prepare(IntRect arena);

	//spawn the pickup
	void spawn();

	//to set the arena in which the player will spawn
	void setArena(IntRect arena);

	//check the position of the pickup
	FloatRect getPosition();

	//check wether the pickup is spawned;
	bool isSpawned();

	//get the pickup sprite
	Sprite getSprite();

	//when the players gets the pickup
	int gotIt();

	//update the value of the pickup
	void update(float elapsedTime);

	//for upgrading the pickup
	void upgrade();

};

