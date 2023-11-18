#pragma once
#include "state.h"
#include "system.h"
#include "mapfeature.hpp"
#include "maincharacter.hpp"
#include "enemy.hpp"
#include <vector>
#include "car.hpp"
class map : public state
{
private:
    bool mescpressed = false;
    std ::vector<block *> blocks;
    data *_data;
    std ::vector<car *> enemies;
    maincharacter *player;
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std::vector<sf::Vector2i> enemyPos;
    int currentIndex;

    sf::Texture backgroundTexture;

public:
    std::vector<sf::Vector2f> roadpos;
    int length;
    std::vector<sf::Vector2f> river;
    map(data *data);
    map();
    void addcar();
    bool addedroad = false;
    int newRoadIdx = -1;
    ~map()
    { // delete dynamically alocated memory

        for (int i = 0; i < blocks.size(); i++)
        {
            delete blocks[i];
        }
        delete player;
    }
    void init();
    void processInput();
    void update();
    void draw();
    void createmap();
    void addblock(std::string terrainName);
    sf::RectangleShape background;
};