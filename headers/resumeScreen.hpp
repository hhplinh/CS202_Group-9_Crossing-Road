#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>


#include <iostream>

class ResumeScreen : public state
{
private:
    data *_data;
    
    sf::Clock clock;
    bool isPaused;
    int countdown;

    sf::Text countdownText;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;


public:
    ResumeScreen(data *data);
    ~ResumeScreen();

    void init();
    void processInput();
    void update();
    void draw();
};
