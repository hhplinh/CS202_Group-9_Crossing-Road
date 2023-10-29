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
	//obstaclepos.clear();
//obstaclepos.push_back(sf::Vector2i(0, 2)); //Insert obstacle position here
//	obstaclepos.push_back(sf::Vector2i(6, 0));
//	obstaclepos.push_back(sf::Vector2i(2, 7));
}

void gameWorld::setUpTerrain()
{
    tiles.clear();

    // Define the available terrain types
    const std::vector<std::string> terrainTypes = 
	{
        "Road", "River", "Rock 1", "Rock 2", "Traffic light", "Car 1", "Car 2", "Car 3", "Car 4",
        "Car 5",   "Tree 1"
    };

    for (int i = 0; i < gridLength; i++) {
        std::vector<TerrainBlock*> row;

        // Generate a row with random terrain types
        for (int j = 0; j < gridLength; j++) {
            int terrainIndex = std::rand() % terrainTypes.size();
            row.push_back(new TerrainBlock("resources/" + terrainTypes[terrainIndex] + ".png", j * 100, i *200 , true, false));
        }

        tiles.push_back(row);
    }
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
void gameWorld::render(sf::RenderTarget* target)
{
    for (int i = 0; i < gridLength; i++)
    {
        for (int j = 0; j < gridLength; j++)
        {
            target->draw(this->tiles[i][j]->sprite);
        }
    }
}