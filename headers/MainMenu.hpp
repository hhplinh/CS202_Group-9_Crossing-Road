#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class MainMenu
{
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;
    int MAX_NUMBER_OF_ITEMS = 5;

public:
    // MainMenu(){};
    // ~MainMenu(){};
    void create(float width, float height);
    void renderNavigateWithButtons();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();

    void a();

};

#endif