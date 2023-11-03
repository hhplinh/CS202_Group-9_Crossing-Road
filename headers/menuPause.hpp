#pragma once
#include "state.h"
#include "system.h"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <map>

class menuPause : public state
{
private:
    enum Button
    {
        RESUME,
        MAIN_MENU,
        NUM_BUTTONS
    };

    std::map<Button, std::string> buttonToString = {
        {RESUME, "Resume"},
        {MAIN_MENU, "Main Menu"}};

    data *_data;
    sf::RectangleShape background;

    std::vector<sf::Text> m_buttons;

    const sf::Color COLOR_SELECT = sf::Color(248, 153, 56, 255);

    std::vector<bool> m_buttonsSelected{};
    std::vector<bool> m_buttonsPressed{};

public:
    menuPause(data *data);
    ~menuPause();
    void init();
    void processInput();
    void update();
    void draw();
};