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

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LOAD, "Load"},
        {SETTINGS, "Settings"},
        {EXIT, "Exit"}};

    data *_data;
    sf::RectangleShape background;

    // sf::Text m_play;
    // sf::Text m_exit;
    // sf::Text m_load;
    // sf::Text m_settings;

    std::vector<sf::Text> m_buttons;

    const sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255);

    std::vector<bool> m_buttonsSelected{};
    std::vector<bool> m_buttonsPressed{};

    // bool m_playselected;
    // bool m_exitselected;
    // bool m_playpressed;
    // bool m_exitpressed;
    // sf::Text m_loadGame;
    // bool m_loadGameSelected;
    // bool m_loadGamePressed;

    // bool m_settingsSelected;
    // bool m_settingsPressed;

public:
    menu(data *data);
    ~menu();
    void init();
    void processInput();
    void update();
    void draw();

    bool isOnlyOneButtonOn(const std::vector<bool> &buttons);
    void turnOnButtonKeyDown(std::vector<bool> &buttonsSelected);
    void turnOnButtonKeyUp(std::vector<bool> &buttonsSelected);
    void turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed);
    void setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected);
};