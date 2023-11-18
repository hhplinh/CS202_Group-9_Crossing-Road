#pragma once
#include "state.h"
#include "system.h"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>

class menu : public state
{
protected:
    data *_data;
    sf::RectangleShape background;

    std::vector<sf::Text> m_buttons{};

    const sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255);

    std::vector<bool> m_buttonsSelected{};
    std::vector<bool> m_buttonsPressed{};

    bool isEventChanged = true;

public:
   
    menu(data *data);
    ~menu();

    void draw();

    bool isOnlyOneButtonOn(const std::vector<bool> &buttons);
    void turnOnButtonKeyDown(std::vector<bool> &buttonsSelected);
    void turnOnButtonKeyUp(std::vector<bool> &buttonsSelected);
    void turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed);
    void setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected, sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255));
};
