#include "Boat.hpp"
#include <random>

Boat::Boat(data* _data) : _data(_data) {
    sprite.setTexture(_data->_assets->getTexture(BOAT));

    int z = rand() % 2;
    this->speed = 2.5f;

    if (z == 1) {
        this->isMovingRight = true;
        this->sprite.setPosition(1000, 300); // Set the initial position
    }
    else {
        this->isMovingRight = false;
        this->sprite.setPosition(100, 300); // Set the initial position
    }
}

sf::FloatRect Boat::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Boat::setPosCano(sf::Vector2f posRiver) {
    sprite.setPosition(sprite.getPosition().x, posRiver.y);
}

void Boat::turnAround() {
    isMovingRight = !isMovingRight;
}

void Boat::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Boat::setSpeed(float speed) {
    this->speed = speed;
}

float Boat::getSpeed() {
    return this->speed;
}

void Boat::floatOnRiver() {
    if (isMovingRight) {
        sprite.move(speed, 0);
    }
    else {
        sprite.move(-speed, 0);
    }
}

sf::Vector2f Boat::getPosCano() {
    return sprite.getPosition();
}
