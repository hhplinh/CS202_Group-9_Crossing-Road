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
        DIFFICULTY,
        SETTINGS,
        EXIT,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LOAD, "Load"},
        {DIFFICULTY, "Difficulty"},
        {SETTINGS, "Settings"},
        {EXIT, "Exit"},
    };
        // {PAUSE, "Pause"},
        // {END, "End"}

public:

    mainMenu(data *data);
    ~mainMenu();
    void init();
    void processInput();
    void update();
    void draw();
};