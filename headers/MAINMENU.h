#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#define MAX_NUMBER_OF_ITEMS 5
class Menu
{

public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};