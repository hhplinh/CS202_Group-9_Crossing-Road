#pragma once
#include"state.h"
#include"system.h"
#include"maincharacter.hpp"
#include"mapfeature.hpp"
#include"map.hpp"
#include"menu.hpp"
class gameplay : public state 
{   private :
    map* _map;
    data* _data;
    maincharacter* player;
    public :
    gameplay(data* data);
    ~gameplay();
    void init();
    void processInput();
    void update();
    void draw();
    void createmap();

};