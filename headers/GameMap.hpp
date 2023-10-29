#include <SFML/Graphics.hpp>
#include "TerrainBlock.hpp"
#include <vector>
#ifndef GAMEWORLD_H	
#define GAMEWORLD_H
class gameWorld
{
private:
	sf::Vector2i deathPos;
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> obstaclepos;
	void setUpInitialState();
	void setUpObstaclePositions();
	void setUpTerrain();
public:
	std::vector<std::vector<TerrainBlock*>> tiles;
	int gridLength;
	gameWorld();
	~gameWorld();
	void render(sf:: RenderTarget *target);

};
#endif