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
    virtual std::unique_ptr<ScreenMenu> render();
};

class HomeMenu : public ScreenMenu
{
private:
    const int MAX_NUMBER_OF_ITEMS = 5;
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

public:
    std::unique_ptr<ScreenMenu> render();

    void draw();
};

class SettingMenu : public ScreenMenu
{
private:
    const int MAX_NUMBER_OF_ITEMS = 5;
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

public:
    std::unique_ptr<ScreenMenu> render();

    void draw();
};

#endif