#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <string>

struct Player {
    std::string name;
    int score;

    // Overload the "<" operator for sorting
    bool operator<(const Player& rhs) const {
        return score > rhs.score;  // sort in descending order of scores
    }
};

class inputNameHighScore : public state
{
private:
    data *_data;

    bool isEventChanged = true;
    sf::RectangleShape backgroundSprite;

    const std::string SCORES_PATH = "scores.bin";
    const int NUM_SCORES = 5;
    
    std::string input{};

    sf::Text inputName;

public:
    inputNameHighScore(data *data);
    ~inputNameHighScore();

    void init();
    void processInput();
    void update();
    void draw();
};