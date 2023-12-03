#include "enemy.hpp"
#include "system.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "cano.hpp"

Cano::Cano(data* _data) : _data(_data) {
    sprite.setTexture(_data->_assets->getTexture(CANO));

    int z = rand() % 2;
    this->speed = 3;

    if (z == 1) {
        this->isMovingRight = true;
        this->sprite.setPosition(1000, 0); // Set the initial position
    }
    else {
        this->isMovingRight = false;
        this->sprite.setPosition(1000, 0); // Set the initial position
    }
}

sf::FloatRect Cano::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Cano::setPosCano(sf::Vector2f posRiver) {
    sprite.setPosition(sprite.getPosition().x, posRiver.y);
}

void Cano::turnAround() {
    isMovingRight = !isMovingRight;
    //rotate the sprite around the center of the sprite

    
    


}

void Cano::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Cano::setSpeed(float speed) {
    this->speed = speed;
}

float Cano::getSpeed() {
    return this->speed;
}

void Cano::floatOnRiver() {
    if (isMovingRight) {
        sprite.move(speed, 0);
    }
    else 
    {   
        sprite.move(-speed, 0);
    }
}

sf::Vector2f Cano::getPosCano() {
    return sprite.getPosition();
}
