#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"state.h"
#include"system.h"

class Enemy {
protected:
    float x;
    float y;
    float speed;
    data* _data;
public:
    virtual void move() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void die(float playerX, float playerY) = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual ~Enemy() = default;
};

class Car : public Enemy {
public:
    Car(float startX, float startY, float speed);
    void move() override;
    void draw(sf::RenderWindow& window) override;
    void die(float playerX, float playerY) override;
    sf::FloatRect getBounds() const override;
};

class Animal : public Enemy {
public:
    Animal(float startX, float startY, float speed);

    void move() override;
    void draw(sf::RenderWindow& window) override;
    void die(float playerX, float playerY) override;
    sf::FloatRect getBounds() const override;
};

class Wood : public Enemy {
public:
    Wood(float startX, float startY, float speed);

    void move() override;
    void draw(sf::RenderWindow& window) override;
    void die(float playerX, float playerY) override;
    sf::FloatRect getBounds() const override;
};

class Spawn {
private:
    std::vector<Enemy*> enemies;
    data* _data;
public:
    Spawn();
    ~Spawn();

    void spawnCar(float startY, float speed);
    void spawnAnimal(float startY, float speed);
    void spawnWood(float startY, float speed);
    void update(float playerX, float playerY);
};
