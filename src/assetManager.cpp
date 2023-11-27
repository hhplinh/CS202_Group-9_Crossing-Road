#include "assetManager.h"
#include <fstream>
#include <cstdio>

assetManager::assetManager()
{
	addTexture(TRAFFICLIGHT, "resources//Texture//Traffic light.png");
	addTexture(BACKGROUND, "resources//Texture//bgMenu.png");
	addTexture(BG_INPUT_NAME, "resources//Texture//bgInputName.png");
	addTexture(LEADERBOARD, "resources//Texture//leaderboard.png");
	addTexture(ROAD, "resources//Texture//road.png");
	addTexture(RIVER, "resources//Texture//River.png");
	addFont(MAIN_FONT, "resources//Font//LilitaOne-Regular.ttf");
	addFont(FONT2, "resources//Font//BlackOpsOne-Regular.ttf");
	addTexture(GRASS, "resources//Texture//grass.png");
	addTexture(CAR, "resources//Texture//Car 1.png");
	addTexture(CAR2, "resources//Texture//Car 2.png");
	addTexture(CAR3, "resources//Texture//Car 3.png");
	addTexture(CAR4, "resources//Texture//Car 4.png");
	addTexture(CAR5, "resources//Texture//Car 5.png");
	addTexture(CANO, "resources//Texture//Cano.png");
	addTexture(CANO2, "resources//Texture//Cano 2.png");
	addTexture(COP, "resources//Texture//cop.png");
	addTexture(VOI, "resources//Texture//Voi.png");
	addTexture(GAU, "resources//Texture//Gau.png");
	addTexture(TEGIAC, "resources//Texture//Tegiac.png");
	addTexture(LACDA, "resources//Texture//Lacda.png");
	addTexture(PENGUIN, "resources//Texture//Penguin.png");
	addTexture(DIRT, "resources//Texture//dirt.png");
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

bool assetManager::isEasyLevelSavedGame()
{
	std::ifstream file(PATH_SAVED_GAME, std::ios::binary);
	if (file.good())
	{
		file.read((char *)&isEasyLevelSaved, sizeof(bool));
		return isEasyLevelSaved;
	}
	else
	{
		std::cerr << "Error: file not open in check easy level\n";
		return 0;
	}
	file.close();
	return 1;
}