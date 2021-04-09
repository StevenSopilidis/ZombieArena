#include "ZombieArena.h"

int createBackground(sf::VertexArray& rVA, sf::IntRect arena)
{
	//anything done to the rVA is really done 
	//to the background (in the main function)

	//size in pixels of each tile within the sprite sheet
	const int TILE_SIZE = 50;
	//number of tile types that exist in the SPRITE_Sheet
	const int TILE_TYPES = 3;
	//numer of vertices in a Quad primitime type
	const int VERTS_IN_QUAD = 4;

	//height and width of the world (int tiles)
	int worldWidth = arena.height / TILE_SIZE;
	int worldHeight = arena.width / TILE_SIZE;

	//What type of primitive we are using (quads, triangles, points, lines )
	rVA.setPrimitiveType(sf::Quads);
	//set the size of the vertext array
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	//Start at the beggining of the vertext array
	int currentVertex = 0;

	//start at the beggining of the vertext array
	for (size_t w = 0; w < worldWidth; w++)
	{
		for (size_t h = 0; h < worldHeight; h++)
		{
			//position each vertex in the current quad

			/// top left of quad
			rVA[currentVertex + 0].position =
				sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);

			/// top right of quad
			rVA[currentVertex + 1].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

			/// bottom right of the quad
			rVA[currentVertex + 2].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

			/// bottom left of the quad
			rVA[currentVertex + 3].position =
				sf::Vector2f(w * TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

			//Define the position in the TEXTURE (From spriteSheet) for current quad
			//Either grass, stone, bush or wall
			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				//Use the wall texture
				
				rVA[currentVertex + 0].texCoords =
					sf::Vector2f(0, 0 + TILE_SIZE * TILE_TYPES);

				rVA[currentVertex + 1].texCoords =
					sf::Vector2f(TILE_SIZE, 0 + TILE_SIZE * TILE_TYPES);

				rVA[currentVertex + 2].texCoords =
					sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_SIZE * TILE_TYPES);

				rVA[currentVertex + 3].texCoords =
					sf::Vector2f(0, TILE_SIZE + TILE_SIZE * TILE_TYPES);
			}
			else {
				//either grass stone or bush or wall 
				//use a random floor texture
				srand((int)time(0) + h * w - h);
				//so we pick one tile type randomly
				int mOrG = (rand() % TILE_TYPES);
				//vertical offeset in the spite sheet
				int verticalOffeset = mOrG * TILE_SIZE;
				
				rVA[currentVertex + 0].texCoords =
					sf::Vector2f(0, 0 + verticalOffeset);

				rVA[currentVertex + 1].texCoords =
					sf::Vector2f(TILE_SIZE, 0 + verticalOffeset);

				rVA[currentVertex + 2].texCoords =
					sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffeset);

				rVA[currentVertex + 3].texCoords =
					sf::Vector2f(0, TILE_SIZE + verticalOffeset);
			}
			//Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
		
	}


	return TILE_SIZE;
}