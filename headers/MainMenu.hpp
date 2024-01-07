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
        MUSIC_ON,
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
        {MUSIC_ON, "Music On"},
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