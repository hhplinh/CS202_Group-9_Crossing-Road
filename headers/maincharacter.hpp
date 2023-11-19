#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include"state.h"
#include"system.h"
//#include"menu.hpp"




class maincharacter //public state
{
    private : int row , col;
    bool isFallen;
    data * _data;
    sf :: RectangleShape shape;
    sf::Texture texture;
    sf::Sprite p;
    bool movingRight;
    bool movingUp;
    sf::Clock moveCooldownTimer;
    bool movingLeft;
    sf::Vector2f velocity;
    bool mApressed=0;
    void setView();
     int stamina;
    int MAX_STAMINA;
    float staminaRecoveryRate;
    float staminaDrainRate;
    bool isMoving;
        sf::RectangleShape staminaBar;
    sf::RectangleShape staminaBarBackground;
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
    
    void updateStamina(); // Method to update the character's stamina
    void displayStamina(); // Method to update the stamina bar size
    void drawStaminaBar(sf::RenderTarget& target) const;
    //get the stamina bar state
    int getStamina() const { return stamina; }
};
