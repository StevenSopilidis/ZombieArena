#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
private:
	//position of the bullet
	Vector2f m_Position;

	//shape of the bullet
	RectangleShape m_BulletShape;

	//is the bullet in the whizzing throught the air
	bool m_InFlight = false;

	//bullets speed
	float m_BulletSpeed = 1000.f;

	// What fraction of 1 pixel does the bullet travel,     
	// Horizontally and vertically each frame?
	// These values will be derived from m_BulletSpeed
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	//boundaries so the bullet wont fly forever
	float m_MaxY;
	float m_MaxX;
	float m_MinY;
	float m_MinX;
public:
	Bullet();

	//stop the bullet
	void stop();

	//returns the value of m_InFlight
	bool isInFlight();

	//Lauch a new bullet
	//(float xTarget, float yTarget) -> position of the crossHair
	void shoot(float startX, float startY, float xTarget, float yTarget);

	//where the bullet is relative to the game world
	FloatRect getPosition();

	//returns the actual bullet shape (for drawing)
	RectangleShape getShape();

	//update the bullet eachFrame
	void update(float elapsedTime);
};

