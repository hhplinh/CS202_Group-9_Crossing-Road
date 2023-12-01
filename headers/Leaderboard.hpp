#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string name;
    int score;

    // Overload the "<" operator for sorting
    bool operator<(const Player& rhs) const {
        return score > rhs.score;  // sort in descending order of scores
    }
};

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