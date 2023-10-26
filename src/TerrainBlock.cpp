#include <SFML/Graphics.hpp>
#include "TerrainBlock.hpp"

terrainBlock::TerrainBlock(std::string terrainName, float x, float y, bool isPassable)
{
	if (!setUpSprite(terrainName))
	{
		return;
	}
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
}

bool TerrainBlock::setUpSprite(std::string terrainName)
{
	sf::Texture texture;
	if (!texture.loadFromFile(terrainName))
	{
		return false;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 100, 1080));
	return true;
}
