#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

class Leaderboard : public state
{
private:
    data *_data;
    const std::string INSTRUCT_PATH = "instruction.txt";
    sf::Text instructText;
    sf::RectangleShape backgroundSprite;
    std::vector<sf::Text> name_score;

    const std::string SCORES_PATH = _data->_assets->getHighScorePath();


public:
    Leaderboard(data *data);
    ~Leaderboard();

    void init();
    void processInput();
    void update();
    void draw();
};