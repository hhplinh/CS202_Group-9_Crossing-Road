#pragma once

#include "menu.hpp"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <map>

class mainMenu : public menu
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

public:

    mainMenu(data *data);
    ~mainMenu();
    void init();
    void processInput();
    void update();
    void draw();
};