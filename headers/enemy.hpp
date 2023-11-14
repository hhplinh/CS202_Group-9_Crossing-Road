#include"system.h"
#pragma once
class enemy
{ 
    private :
    data * _data;
    public:
    sf :: Sprite sprite;   
    virtual void foo( )=0;
};