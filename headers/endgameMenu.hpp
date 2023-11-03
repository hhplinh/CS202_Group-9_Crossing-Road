#pragma once
#include "state.h"
#include "system.h"
#include "map.hpp"
#include "maincharacter.hpp"
#include "menu.hpp"


#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <map>

class endgameMenu : public state, public menu
{
private:
    enum Button
    {
        RESTART,
        MAIN_MENU,
        NUM_BUTTONS
    };

    std::map<Button, std::string> buttonToString = {
        {RESTART, "Restart"},
        {MAIN_MENU, "Main Menu"}};

    data *_data;
    sf::RectangleShape background;
    std::vector<sf::Text> m_buttons;
    sf::Text score;

    const sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255);

    std::vector<bool> m_buttonsSelected{};
    std::vector<bool> m_buttonsPressed{};

public:
    endgameMenu(data *data);
    ~endgameMenu();
    void init();
    void processInput();
    void update();
    void draw();

    // bool isOnlyOneButtonOn(const std::vector<bool> &buttons);
    // void turnOnButtonKeyDown(std::vector<bool> &buttonsSelected);
    // void turnOnButtonKeyUp(std::vector<bool> &buttonsSelected);
    // void turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed);
    // void setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected);
};