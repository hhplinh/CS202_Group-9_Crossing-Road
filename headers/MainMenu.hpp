#pragma once

#include "menu.hpp"
#include <map>

class mainMenu : public menu
{
private:

    enum Button
    {
        PLAY,
        LOAD,
        INSTRUCTION,
        LEADERBOARD,
        EXIT,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LOAD, "Load"},
        {INSTRUCTION, "Instruction"},
        {LEADERBOARD, "Leaderboard"},
        {EXIT, "Exit"},
    };

public:

    mainMenu(data *data);
    virtual ~mainMenu();
    void init();
    void processInput();
    void update();
};