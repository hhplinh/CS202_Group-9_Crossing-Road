#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <Library.hpp>

#define Max_Number_Of_Items 5

class MainMenu
{
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();

    void MoveLeft();
    void MoveRight();

    void render();
};

#endif