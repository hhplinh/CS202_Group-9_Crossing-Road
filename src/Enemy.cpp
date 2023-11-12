#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void Car::init()
{
        sf::Sprite car1, car2, car3, car4, car5;
        sf::Vector2u size1 = _data->_assets->getTexture(CAR1).getSize();
        sf::Vector2u size2 = _data->_assets->getTexture(CAR2).getSize();
        sf::Vector2u size3 = _data->_assets->getTexture(CAR3).getSize();
        sf::Vector2u size4 = _data->_assets->getTexture(CAR4).getSize();
        sf::Vector2u size5 = _data->_assets->getTexture(CAR5).getSize();
        car1.setTexture(_data->_assets->getTexture(CAR1));
        car2.setTexture(_data->_assets->getTexture(CAR2));
        car3.setTexture(_data->_assets->getTexture(CAR3));
        car4.setTexture(_data->_assets->getTexture(CAR4));
        car5.setTexture(_data->_assets->getTexture(CAR5));
        car.push_back(car1);
        car.push_back(car2);
        car.push_back(car3);
        car.push_back(car4);
        car.push_back(car5);
        size.push_back(size1);
        size.push_back(size2);
        size.push_back(size3);
        size.push_back(size4);
        size.push_back(size5);
        carNumber = rand() % 5;
        car[carNumber].setPosition(rand() % 1920 + size[carNumber].x, 50);
        velocity.x = 100;
        velocity.y = 0;

        //velocity.x = 0;
        //velocity.y = 0;

        //size.x = size.x / col;
        //size.y = size.y / row;

        //p.setTextureRect(sf::IntRect(0, size.y * 3, size.x, size.y));
        mApressed = false;

}

// Car implementation
Car::Car(float startX, float startY) : Enemy() {

}

void Car::move() {
    x += velocity.x;
    if (x < 0) {
        x -= velocity.x;
    }
}

void Car::draw() {
    _data->_window->draw(car[carNumber]);
}

void Car::die(float playerX, float playerY) {
    if (getBounds().intersects(sf::FloatRect(playerX, playerY, 50, 50))) {
        std::cout << "Player collided with Car! Player dies." << std::endl;
    }
}

sf::FloatRect Car::getBounds() const {
    return sf::FloatRect(x, y, 50, 50);
}

// Animal implementation
Animal::Animal(float startX, float startY, float speed) : Enemy() {
    x = startX;
    y = startY;
    this->speed = speed;
}

void Animal::init()
{
}

void Animal::move() {
    x += speed;
    if (x > 800) {
        x = 0;
    }
}

void Animal::draw() {
    //sf::CircleShape animal(25);
    //animal.setPosition(x, y);
    //animal.setFillColor(sf::Color::Green);
    //window.draw(animal);
}

void Animal::die(float playerX, float playerY) {
    if (getBounds().intersects(sf::FloatRect(playerX, playerY, 50, 50))) {
        std::cout << "Player collided with Animal! Player dies." << std::endl;
    }
}

sf::FloatRect Animal::getBounds() const {
    return sf::FloatRect(x, y, 50, 50);
}

// Wood implementation
Wood::Wood(float startX, float startY, float speed) : Enemy() {
    x = startX;
    y = startY;
    this->speed = speed;
}

void Wood::init()
{
}

void Wood::move() {
    x += speed;
    if (x > 800) {
        x = 0;
    }
}

void Wood::draw() {
    //sf::RectangleShape wood(sf::Vector2f(100, 25));
    //wood.setPosition(x, y);
    //wood.setFillColor(sf::Color::Yellow);
    //window.draw(wood);
}

void Wood::die(float playerX, float playerY) {
    if (getBounds().intersects(sf::FloatRect(playerX, playerY, 50, 50))) {
        std::cout << "Player collided with Wood! Player dies." << std::endl;
    }
}

sf::FloatRect Wood::getBounds() const {
    return sf::FloatRect(x, y, 100, 25);
}

// Spawn implementation
Spawn::Spawn() {}

Spawn::~Spawn() {
    for (auto enemy : enemies) {
        delete enemy;
    }
}

void Spawn::spawnCar(float y, float speed) {
    enemies.push_back(new Car(960.0, 540.0));
}

void Spawn::spawnAnimal(float startY, float speed) {
    //enemies.push_back(new Animal(0, startY, speed));
}

void Spawn::spawnWood(float startY, float speed) {
    //enemies.push_back(new Wood(0, startY, speed));
}

void Spawn::update(float playerX, float playerY) {
    for (auto& enemy : enemies) {
        enemy->move();
        enemy->die(playerX, playerY);
    }
}

