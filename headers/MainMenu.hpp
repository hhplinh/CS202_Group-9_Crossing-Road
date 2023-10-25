#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <Library.hpp>

class MainMenu
{
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;
    int MAX_NUMBER_OF_ITEMS = 5;

public:
    MainMenu(){};
    ~MainMenu(){};

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();

    void create(float width, float height);
    void render();
};

#endif