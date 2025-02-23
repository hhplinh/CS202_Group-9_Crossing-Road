#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "system.h"
// #include"menu.hpp"

class maincharacter // public state
{
protected:
    int row, col;
    bool isFallen;
    data *_data;
    sf ::RectangleShape shape;
    sf::Texture texture;
    sf::Sprite p;
    bool movingRight;
    bool movingDown;
    bool movedDown;
    bool isDead;
    sf::Vector2f moveCamPos;

    sf::Clock moveCooldownTimer;
    sf::Clock movingDownTimer;

    bool movingLeft;
    sf::Vector2f velocity;
    bool mApressed = 0;
    void setView();
    int stamina;
    int MAX_STAMINA;
    float staminaRecoveryRate;
    float staminaDrainRate;
    bool isMoving;
    sf::RectangleShape staminaBar;
    sf::RectangleShape staminaBarBackground;

public:
    bool movingUp;
    maincharacter(data *_data);
    sf::View camera;
    void init();
    void processInput(sf ::Event event);
    void processInput();
    virtual void update();
    virtual void draw();
    virtual void processMovedDown();
    void move();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    sf::Vector2u size;
    sf::Sprite getSprite()
    {
        return this->p;
    }
    sf::Vector2f getPosPlayer();
    void updateStamina();  // Method to update the character's stamina
    void displayStamina(); // Method to update the stamina bar size
    void drawStaminaBar(sf::RenderTarget &target) const;
    // get the stamina bar state
    int getStamina() const { return stamina; }

    void setspeed(float speed);
    void setDeadTexture();
    bool getIsDead();
    bool getIsMovedDown();
    sf::Vector2f getMoveCamPos();
    void setMoveCamPos(const sf::Vector2f &_moveCamPos);
};
