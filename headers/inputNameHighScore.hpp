#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <string>

class inputNameHighScore : public state
{
private:
    data *_data;

    bool isEventChanged = true;
    sf::RectangleShape backgroundSprite;

    const std::string SCORES_PATH = _data->_assets->getHighScorePath();
    const int NUM_SCORES = 5;
    const int MAX_NAME_LENGTH = 15;
    
    std::string input{};

    sf::Text inputName;
    sf::Text score;

public:
    inputNameHighScore(data *data);
    ~inputNameHighScore();

    void init();
    void processInput();
    void update();
    void draw();
};