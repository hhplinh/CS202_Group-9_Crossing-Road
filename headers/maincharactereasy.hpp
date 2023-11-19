#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include"state.h"
#include"system.h"
#pragma once
enum State 
{
    IDLE,
    WALKING,
    RUNNING,
    JUMPING,
    FALLING
};
class maincharactereasy //public state
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
    maincharactereasy(data* _data);
    sf::View camera;
    void init();
	void processInput();
	void update();
	void draw();
    void move();
    void resetView(){ camera.reset(sf::FloatRect(0,0,1920,1080));}
    void setPosition(int x,int y);
    sf::Vector2f getPosition();
    sf::Vector2u size ;

};