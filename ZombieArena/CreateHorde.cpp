#include "Zombie.h"
#include "ZombieArena.h"

Zombie* createHorde(int numZombies, IntRect arena)
{
	//array that will hold the zombies
	Zombie* zombies = new Zombie[numZombies];

	//min and max Y position of where the zombies can spawn
	int maxY = arena.height - 20;
	int minY = arena.top + 20;

	//min and max X position of where the zombies can spawn
	int maxX = arena.width - 20;
	int minX = arena.left + 20;

	//create the required Zombies
	for (size_t i = 0; i < numZombies; i++)
	{
		//which side should the zombie spawn (top, bottom, right,left)
		srand(time(0) * i);
		int side = (rand() % 4);
		//for the zombies position
		float x, y;
		switch (side)
		{
		case 0:
			//left
			x = minX;
			y = (rand() % maxY) + minY;
			break;
		case 1:
			//right
			x = maxX;
			y = (rand() % maxY) + minY;
			break;
		case 2:
			//top
			x = (rand() % maxX) + minX;
			y = minY;
			break;
		case 3:
			//bottom
			x = (rand() % maxX) + minX;
			y = maxY;
			break;
		}
		//brawler, crawler or runner
		srand(time(0) * i * 2);
		int type = (rand() % 3);
		//spawn the zombie into the array
		zombies[i].spawn(x,y, type, i);

	}
	return zombies;
}