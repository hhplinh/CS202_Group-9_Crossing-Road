#pragma once
#include"state.h"
#include"system.h"
#include"mapfeature.hpp"
class map: public state
{   private:
    std :: vector < block * > blocks;
    data* _data;
    public:
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