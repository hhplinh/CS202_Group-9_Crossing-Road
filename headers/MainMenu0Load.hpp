#pragma once

#include "menu.hpp"
#include <map>

class mainMenu0Load : public menu
{
private:
    enum Button
    {
        PLAY,
        INSTRUCTION,
        MUSIC_ON,
        LEADERBOARD,
        EXIT,
        NUM_BUTTONS
    };

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LEADERBOARD, "Leaderboard"},
        {MUSIC_ON, "Music On"},
        {INSTRUCTION, "Instruction"},
        {EXIT, "Exit"},
    };

public:
    mainMenu0Load(data *data);
    virtual ~mainMenu0Load();
    void init();
    void processInput();
    void update();
};