#pragma once

#include "menu.hpp"

#include <map>

class diffiMenu : public menu
{
private:
    enum Button
    {
        KID,
        EASY,
        DIFFICULT,
        BACK,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {KID, "Kid"},
        {EASY, "Easy"},
        {DIFFICULT, "Difficult"},
        {BACK, "Back"},
    };

public:

    diffiMenu(data *data);
    ~diffiMenu();
    void init();
    void processInput();
    void update();
};