#include "assetManager.h"
#include <fstream>
#include <cstdio>

assetManager::assetManager()
{
	addTexture(TRAFFICLIGHT, "resources//Texture//Traffic light.png");
	addTexture(BACKGROUND, "resources//Texture//bgMenu.png");
	addTexture(BACKGROUND2, "resources//Texture//Background2.png");
	addTexture(BG_INPUT_NAME, "resources//Texture//bgInputName.png");
	addTexture(LEADERBOARD, "resources//Texture//leaderboard.png");
	addTexture(ROAD, "resources//Texture//road.png");
	addTexture(RIVER, "resources//Texture//River.png");
	addFont(MAIN_FONT, "resources//Font//LilitaOne-Regular.ttf");
	addFont(FONT2, "resources//Font//BlackOpsOne-Regular.ttf");
	addTexture(GRASS, "resources//Texture//grass.png");
	addTexture(CAR, "resources//Texture//Car 1.png");
	addTexture(CAR2, "resources//Texture//car2.png");
	addTexture(CAR3, "resources//Texture//car3.png");
	addTexture(CAR4, "resources//Texture//car4.png");
	addTexture(CAR5, "resources//Texture//car5.png");
	addTexture(CANO, "resources//Texture//Cano.png");
	addTexture(CANO2, "resources//Texture//Cano2.png");
	addTexture(COP, "resources//Texture//cop.png");
	addTexture(VOI, "resources//Texture//Voi.png");
	addTexture(GAU, "resources//Texture//Gau.png");
	addTexture(TEGIAC, "resources//Texture//Tegiac.png");
	addTexture(LACDA, "resources//Texture//Lacda.png");
	addTexture(PENGUIN, "resources//Texture//Penguin.png");
	addTexture(CAT, "resources//Texture//Cat.png");
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
		file.close();
		return isEasyLevelSaved;
	}
	std::cerr << "Error: file not open in check easy level\n";
	file.close();
	return 0;
}

bool assetManager::saveHighScore(const std::string &name, int score)
{
	createHighScoreFile();
	if (isInTopScore(score))
	{
		std::ifstream file(PATH_HIGH_SCORE);
		if (file.good())
		{
			std::vector<std::pair<std::string, int>> topScores;

			int siz;
			file >> siz;

			int minTopScore;
			file >> minTopScore;

			std::string _name;
			int _score;
			while (file >> _name >> _score)
			{
				topScores.push_back(std::make_pair(_name, _score));
			}
			file.close();

			topScores.push_back(std::make_pair(name, score));
			std::sort(topScores.begin(), topScores.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
					  { return a.second > b.second; });

			std::ofstream save(PATH_HIGH_SCORE);
			if (save.good())
			{
				siz = topScores.size();
				if (numHighScores < siz)
				{
					siz = numHighScores;
				}
				save << siz << std::endl;
				save << topScores[siz - 1].second << std::endl;

				for (int i = 0; i < siz; i++)
				{
					save << topScores[i].first << " " << topScores[i].second << std::endl;
				}
				save.close();
				return 1;
			}
			else
			{
				std::cerr << "Error: file not open in save high score\n";
				save.close();
				return 0;
			}
		}
		else
		{
			std::cerr << "Error: file not open in save high score\n";
			file.close();
			return 0;
		}
	}

	return 0;
}

bool assetManager::isInTopScore(int score)
{
	std::ifstream file(PATH_HIGH_SCORE);
	if (file.good())
	{
		int siz;
		file >> siz;

		int minTopScore;
		file >> minTopScore;

		if (siz < numHighScores)
		{
			file.close();
			return 1;
		}

		if (score >= minTopScore)
		{
			file.close();
			return 1;
		}
	}

	std::cerr << "Error: file not open in check top score\n";
	file.close();
	return 0;
}

bool assetManager::createHighScoreFile()
{
	std::ifstream file(PATH_HIGH_SCORE);
	if (file.good())
	{
		file.close();
		return 1;
	}
	else
	{
		file.close();

		std::ofstream fout(PATH_HIGH_SCORE);
		if (fout.good())
		{
			fout << 0 << std::endl;
			fout << 0 << std::endl;
			fout.close();
			return 1;
		}
		else
		{
			std::cerr << "Error: file not open in create high score file\n";
			fout.close();
			return 0;
		}
	}
}