#include <SFML/Graphics.hpp>
#include "TerrainBlock.hpp"
#include <vector>

class gameWorld
{
	sf::Vector2i deathPos;
	std::vector<sf::Vector2i> obstacle;
	void setUpInitialState();
	void setUpObstaclePositions();
	void setUpTerrain();
public:
	std::vector<std::vector<terrainBlock*>> tiles;
	int gridLength;
	gameWorld();

};