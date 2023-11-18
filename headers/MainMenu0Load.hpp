#pragma once

#include "menu.hpp"

#include <map>

class mainMenu0Load : public menu
{
private:

    enum Button
    {
        PLAY,
        SETTINGS,
        EXIT,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {SETTINGS, "Settings"},
        {EXIT, "Exit"},
    };

public:

    mainMenu0Load(data *data);
    ~mainMenu0Load();
    void init();
    void processInput();
    void update();
};