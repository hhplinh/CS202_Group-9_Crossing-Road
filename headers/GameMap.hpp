#include <SFML/Graphics.hpp>
#include "TerrainBlock.hpp"
#include <vector>

class gameWorld
{
private:
	sf::Vector2i deathPos;
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> obstacle;
	void setUpInitialState();
	void setUpObstaclePositions();
	void setUpTerrain();
public:
	std::vector<std::vector<TerrainBlock*>> tiles;
	int gridLength;
	gameWorld();

};