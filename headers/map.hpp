#pragma once
#include"state.h"
#include"system.h"
#include"mapfeature.hpp"
#include"maincharacter.hpp"
class map: public state
{   private:
    std :: vector < block * > blocks;
    data* _data;
    maincharacter * player;
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std:: vector <sf::Vector2i> enemyPos;

    public:
    std::vector < std:: vector < block* > > tiles;
    int length;

    map(data* data);
    map();
    ~map();
    void init();
    void processInput();
    void update();
    void draw();
    void createmap();
    void addblock( std:: string terrainName);
    sf::RectangleShape background;
};