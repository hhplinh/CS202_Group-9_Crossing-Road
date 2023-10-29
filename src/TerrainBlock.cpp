#include <SFML/Graphics.hpp>
#include "TerrainBlock.hpp"
#include <iostream>
TerrainBlock::TerrainBlock(std::string terrainName, float x, float y, bool isPassable, bool isExit)
{
	if (!setUpSprite(terrainName))
	{
		std::cout<<"can't load terrain texture"<<std::endl;
	}
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	this->isPassable = isPassable;
	this->isExit = exit;
}

bool TerrainBlock::setUpSprite(std::string terrainName)
{
	
	if (!texture.loadFromFile(terrainName))
	{   std::cout<<" can't load terrain texture"<<std::endl;
		return false;
	}

	texture.setSmooth(true);
	sprite.setTexture(texture);
	//sprite.setTextureRect(sf::IntRect(0, 0, 400, 500));
	return true;
}
