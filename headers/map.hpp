#pragma once
#include"state.h"
#include"system.h"
#include"mapfeature.hpp"
#include"maincharacter.hpp"
#include"enemy.hpp"
#include <vector>
#include "car.hpp"
#include "cano.hpp"
class map: public state
{   private:
    std :: vector < block * > blocks;
    data* _data;
    std ::  vector < car * > enemies;
    std::vector <Cano*> enemies2;
    maincharacter * player;
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std:: vector <sf::Vector2i> enemyPos;
    int currentIndex;
    public:
    std:: vector < sf:: Vector2f > roadpos;
    int length;
    std:: vector < sf::Vector2f> river;
    std::vector <sf::Vector2f> riverPos;
    map(data* data);
    map();
    void addcar();
    bool addedroad=false;
    bool addedRiver = false;
    int newRoadIdx = -1;
    int newRiverIdx = -1;
    ~map()
    { //delete dynamically alocated memory
      
        for(int i=0;i<blocks.size();i++)
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
    void addblock( std:: string terrainName);
    sf::RectangleShape background;
};