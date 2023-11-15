#pragma once
#include "state.h"
#include "system.h"
#include "maincharacter.hpp"

#include "enemy.hpp"
#include <vector>

#include "car.hpp"
#include "cano.hpp"
#include "menu.hpp"

#include "mapfeature.hpp"

class menuPause;
class endgameMenu;
class map : public state
{
private:
    bool mescpressed = false;
    std ::vector<block *> blocks;
    data *_data;
    std ::vector<car *> enemies;
    std::vector<Cano *> enemies2;
    maincharacter *player;
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std::vector<sf::Vector2i> enemyPos;
    int currentIndex;

    sf::Texture backgroundTexture;

public:
    // get the current window screen
    sf::RenderWindow *getWindow()
    {
        return _data->_window;
    }
    std::vector<sf::Vector2f> roadpos;
    int length;
    std::vector<sf::Vector2f> river;
    std::vector<sf::Vector2f> riverPos;
    map(data *data);
    map();
    void addcar();
    bool addedroad = false;
    bool addedRiver = false;
    int newRoadIdx = -1;
    int newRiverIdx = -1;
    ~map()
    { // delete dynamically alocated memory
      // reset view
        _data->_window->setView(_data->_window->getDefaultView());
        for (int i = 0; i < blocks.size(); i++)
        {
            delete blocks[i];
        }
        delete this->player;
    }
    void init();
    void processInput();
    void update();
    void draw();
    void createmap();
    void addblock(std::string terrainName);
    sf::RectangleShape background;
};