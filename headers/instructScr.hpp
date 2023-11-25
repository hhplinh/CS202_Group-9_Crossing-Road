#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <iostream>

class instructScreen : public state
{
private:
    data *_data;

    sf::Clock clock;
    bool isPaused;
    int countdown;

    sf::Text countdownText;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

public:
    instructScreen(data *data);
    ~instructScreen();

    void init();
    void processInput();
    void update();
    void draw();
};
