#ifndef SCREENMENU_HPP
#define SCREENMENU_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class ScreenMenu
{
private:
    bool checkStrEng(std::string &str);
    bool checkStrViet(std::string &str);

public:
    virtual std::unique_ptr<ScreenMenu> render(sf:: RenderWindow& window);
};

class HomeMenu : public ScreenMenu
{
private:
    const int MAX_NUMBER_OF_ITEMS = 5;
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

public:
    std::unique_ptr<ScreenMenu> render(sf:: RenderWindow& window);

    void draw(sf::RenderWindow &window);

    void setValueButtons(float width, float height);
};

// class SettingMenu : public ScreenMenu
// {
// private:
//     const int MAX_NUMBER_OF_ITEMS = 5;
//     int selectedItemIndex;
//     sf::Font font;
//     std::vector<sf::Text> menu;

// public:
//     std::unique_ptr<ScreenMenu> render(sf:: RenderWindow& window);

//     void draw(sf::RenderWindow &window);

//     void setValueButtons(float width, float height);
// };

#endif