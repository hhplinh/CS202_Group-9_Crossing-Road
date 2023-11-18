#pragma once
#include"SFML/Graphics.hpp"
#include <vector>

enum
{
	PLAYER=0 , BACKGROUND , ROCK , ROCK1 , ROCK2 ,ROCK3 ,ROCK4 , TRAFFICLIGHT , TREE1 , TREE2 , RIVER , ROAD , MAIN_FONT, FONT2 ,GRASS, CAR, CAR2, CAR3, CAR4, CAR5, CANO, CANO2, VOI, TEGIAC, GAU, LACDA, COP , PENGUIN
};
class assetManager
{
private:
	sf::Texture* _textures = new sf::Texture[100];
	sf::Font* _fonts = new sf::Font[100];
	
protected:
	sf::Texture _backgroundTexture;
	sf::Sprite _bgSprite;
	const sf::Color THEME_COLOR = sf::Color(248, 153, 56, 255);

public:
	assetManager();
	~assetManager();
	void addTexture(int id, std::string filePath);
	void addFont(int id, std::string filePath);
	sf::Texture& getTexture(int id);
	sf::Font& getFont(int id);

	void setBackgroundTexture(const sf::Texture& texture);
	sf::Texture getBackgroundTexture();

	void setBackgroundSprite(const sf::Sprite& sprite);
	sf::Sprite getBackgroundSprite();

	sf::Color getThemeColor() { return THEME_COLOR; }
};


