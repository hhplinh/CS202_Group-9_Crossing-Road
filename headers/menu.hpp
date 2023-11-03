#pragma once
#include "state.h"
#include "system.h"
#include "map.hpp"
#include "maincharacter.hpp"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <map>

class menu : public state
{
private:
    enum Button
    {
        PLAY,
        LOAD,
        SETTINGS,
        EXIT,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LOAD, "Load"},
        {SETTINGS, "Settings"},
        {EXIT, "Exit"},
    };
        // {PAUSE, "Pause"},
        // {END, "End"}

    data *_data;
    sf::RectangleShape background;

    std::vector<sf::Text> m_buttons;

    const sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255);

    std::vector<bool> m_buttonsSelected{};
    std::vector<bool> m_buttonsPressed{};

public:
    menu(data *data);
    ~menu();
    void init();
    void processInput();
    void update();
    void draw();
};
bool isOnlyOneButtonOn(const std::vector<bool> &buttons);
void turnOnButtonKeyDown(std::vector<bool> &buttonsSelected);
void turnOnButtonKeyUp(std::vector<bool> &buttonsSelected);
void turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed);
void setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected, sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255));
