//#include "GameWorld.h"
#include "GameMap.hpp"

void gameWorld::setUpInitialState()
{
	deathPos = sf::Vector2i(1, 0); //insert collision pos here
	playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	setUpObstaclePositions();
	setUpTerrain();
}

void gameWorld::setUpObstaclePositions()
{
	obstaclepos.clear();
	obstaclepos.push_back(sf::Vector2i(0, 2)); //Insert obstacle position here
	obstaclepos.push_back(sf::Vector2i(6, 0));
	obstaclepos.push_back(sf::Vector2i(2, 7));
}

void gameWorld::setUpTerrain()
{
	tiles.clear();
	std:: vector < TerrainBlock* > firstrow;
	firstrow.push_back(new TerrainBlock("resources/Road.png", 0, 0, true));

}

gameWorld::gameWorld()
{
	gridLength = 8;// adjust to the model's size
	setUpInitialState();
}
gameWorld::~gameWorld()
{
	for (int i = 0; i < gridLength; i++)
	{
		for (int j = 0; j < gridLength; j++)
		{
			delete tiles[i][j];
		}
	}
}
void gameWorld::render( sf::RenderTarget *target)
{
	//for (int i = 0; i < gridLength; i++)
	//{
	//	for (int j = 0; j < gridLength; j++)
	//	{
			//draw the tiles[i][j]


	target -> draw(this->tiles[0][0]->sprite);



			
		//}
	//}
}