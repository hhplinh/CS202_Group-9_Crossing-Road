#pragma once
#include"SFML/Graphics.hpp"
enum
{
	PLAYER=0 , BACKGROUND , ROCK , ROCK1 , ROCK2 ,ROCK3 ,ROCK4 , TRAFFICLIGHT , TREE1 , TREE2 , RIVER , ROAD , MAIN_FONT, TITLE ,MENU_BOARD
};
class assetManager
{
private:
	sf::Texture* _textures = new sf::Texture[100];
	sf::Font* _fonts = new sf::Font[100];


public:
	assetManager();
	~assetManager();
	void addTexture(int id, std::string filePath);
	void addFont(int id, std::string filePath);
	sf::Texture& getTexture(int id);
	sf::Font& getFont(int id);

};


