#include <SFML/Graphics.hpp>

#ifndef TERRAINBLOCK_H
#define TERRAINBLOCK_H
class TerrainBlock
{
public:
	bool isPassable;
	bool isExit;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	TerrainBlock(std::string, float, float, bool , bool);
	bool setUpSprite(std::string);
};
#endif