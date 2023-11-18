#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include"state.h"
#include"system.h"
//#include"menu.hpp"



enum State 
{
    IDLE,
    WALKING,
    RUNNING,
    JUMPING,
    FALLING
};
class maincharacter : public state
{
    private : int row , col;
    data * _data;
    sf :: RectangleShape shape;
    sf::Texture texture;
    sf::Sprite p;
    sf::Vector2f velocity;
    bool mApressed=0;
    void setView();
    
    public:
    maincharacter(data* _data);
    sf::View camera;
    void init();
	void processInput(sf :: Event event);
    void processInput();
	void update();
	void draw();
    void move();
    void setPosition(int x,int y);
    sf::Vector2f getPosition();
    sf::Vector2u size ;

};
