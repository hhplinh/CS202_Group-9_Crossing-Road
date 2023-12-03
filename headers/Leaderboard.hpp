#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::vector<Player> players;
    std::string name;
    int highScore;
};

std::vector<Player> loadPlayerData(const std::string& filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return players;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Player player;

        if (iss >> player.name >> player.highScore) {
            players.push_back(player);
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return players;
}

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