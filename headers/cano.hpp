#pragma once
#include "enemy.hpp"
#include "system.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

class Cano : public sf::Drawable {
private:
    bool isMovingRight = true;
    float speed;
    data* _data;
    sf::Sprite sprite;
    int row, col;
    sf:: Vector2u size;

public:
    Cano(data* _data);
    void foo();

    sf::FloatRect getGlobalBounds();
    void setPosCano(sf::Vector2f posRiver);
    void turnAround();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setSpeed(float speed);
    float getSpeed();
    void floatOnRiver();
    sf::Sprite  getSprite(){
        
        return this->sprite;
    }
    float getspeed( )
    {
        return this->speed;
    }
    sf::Vector2f getPosCano();
    bool isGoR()
    {
        return this->isMovingRight;
    }

    void setGoR(bool isMovingRight);
};
