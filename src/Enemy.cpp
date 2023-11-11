#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Car implementation
Car::Car(float startX, float startY, float speed) : Enemy() {
    x = startX;
    y = startY;
    this->speed = speed;
}

void Car::move() {
    x += speed;
    if (x > 800) {
        x = 0;
    }
}

void Car::draw(sf::RenderWindow& window) {
    sf::RectangleShape car(sf::Vector2f(50, 50));
    car.setPosition(x, y);
    car.setFillColor(sf::Color::Red);
    window.draw(car);
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

void Animal::move() {
    x += speed;
    if (x > 800) {
        x = 0;
    }
}

void Animal::draw(sf::RenderWindow& window) {
    sf::CircleShape animal(25);
    animal.setPosition(x, y);
    animal.setFillColor(sf::Color::Green);
    window.draw(animal);
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

void Wood::move() {
    x += speed;
    if (x > 800) {
        x = 0;
    }
}

void Wood::draw(sf::RenderWindow& window) {
    sf::RectangleShape wood(sf::Vector2f(100, 25));
    wood.setPosition(x, y);
    wood.setFillColor(sf::Color::Yellow);
    window.draw(wood);
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

void Spawn::spawnCar(float startY, float speed) {
    enemies.push_back(new Car(0, startY, speed));
}

void Spawn::spawnAnimal(float startY, float speed) {
    enemies.push_back(new Animal(0, startY, speed));
}

void Spawn::spawnWood(float startY, float speed) {
    enemies.push_back(new Wood(0, startY, speed));
}

void Spawn::update(float playerX, float playerY) {
    for (auto& enemy : enemies) {
        enemy->move();
        enemy->die(playerX, playerY);
    }
}
