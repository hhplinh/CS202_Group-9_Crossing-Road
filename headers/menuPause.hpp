#pragma once

#include "menu.hpp"

#include <map>
 class menuPause : public menu
{
private:
    enum Button
    {
        RESUME,
        MAIN_MENU,
        NUM_BUTTONS
    };

    std::map<Button, std::string> buttonToString = 
    {
        {RESUME, "Resume"},
        {MAIN_MENU, "Main Menu"}
    };

public:
    menuPause(data *data);
    ~menuPause();
    void init();
    void processInput();
    void update();
};