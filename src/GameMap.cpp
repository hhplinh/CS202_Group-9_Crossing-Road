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
}

void gameWorld::setUpTerrain()
{
	obstacle.clear();
	obstacle.push_back(sf::Vector2i(0, 0)); //Insert obstacle position here
	obstacle.push_back(sf::Vector2i(0, 0));
	obstacle.push_back(sf::Vector2i(0, 0));
}

gameWorld::gameWorld()
{
	gridLength = 8;// adjust to the model's size
	setUpInitialState();
}
