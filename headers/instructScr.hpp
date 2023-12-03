#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>
#include <string>
// #include <SFML/Graphics/Shape.hpp>
// #include <SFML/Graphics/RoundedRectangle.hpp>
#include "RoundedRectangle.hpp"

class instructScreen : public state
{
private:
    data *_data;
    const std::string INSTRUCT_PATH = "instruction.txt";
    sf::Text instructText;
    sf::RectangleShape backgroundSprite;
    sf::RectangleShape board;
    sf::RoundedRectangleShape roundedRectangle;
    bool isEventChanged = true;

public:
    instructScreen(data *data);
    ~instructScreen();

    void init();
    void processInput();
    void update();
    void draw();
    std::string loadTextFromFile(const std::string& filename);
};

