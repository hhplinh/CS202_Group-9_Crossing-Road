#pragma once

#include "menu.hpp"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <map>

class diffiMenu : public menu
{
private:

    enum Button
    {
        EASY,
        DIFFICULT,
        BACK,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
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
    void draw();
};