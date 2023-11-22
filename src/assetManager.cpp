#include "assetManager.h"
#include <fstream>
#include <cstdio>

assetManager::assetManager()
{
}
assetManager::~assetManager()
{
}
void assetManager::addTexture(int id, std::string filePath)
{
	sf::Texture texture;
	if (texture.loadFromFile(filePath))
	{
		_textures[id] = texture;
	}
}
void assetManager::addFont(int id, std::string filePath)
{
	sf::Font font;
	if (font.loadFromFile(filePath))
	{
		_fonts[id] = font;
	}
}

sf::Texture &assetManager::getTexture(int id)
{
	return _textures[id];
}
sf::Font &assetManager::getFont(int id)
{
	return _fonts[id];
}

void assetManager::setBackgroundTexture(const sf::Texture &texture)
{
	_backgroundTexture = texture;
}

sf::Texture assetManager::getBackgroundTexture()
{
	return _backgroundTexture;
}

void assetManager::setBackgroundSprite(const sf::Sprite &sprite)
{
	_bgSprite = sprite;
}

sf::Sprite assetManager::getBackgroundSprite()
{
	return _bgSprite;
}

bool assetManager::isGameSaved()
{
	std::ifstream file(PATH_SAVED_GAME);
	if (file.good())
	{
		return 1;
	}
	return 0;
}

bool assetManager::removeSavedGameFile()
{
	if (remove(PATH_SAVED_GAME.c_str()) != 0)
	{
		perror("Error deleting file");
		return 0;
	}
	else
	{
		puts("File successfully deleted");
		return 1;
	}
}