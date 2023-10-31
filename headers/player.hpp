#pragma once
#include <iostream>
#include"state.h"
#include"system.h"
#include <SFML/Graphics.hpp>

class player: public state
{  

    private :
    int row , col;
    data * _data;
    sf :: RectangleShape shape;
    
    public :
     void initvariables();
    
    void initshape();
    player(data* _data);
    
    void init();
	void processInput();
	void update();
	void draw();
     //
    sf:: Texture texture;
    sf::Sprite p;

   // void LoadContent(std::string path);
 
    void drawchar(sf::RenderWindow &window);
    
    void render(sf:: RenderTarget *target );  
    
    player(std::string path);
    
   
    void move();
 
    void setPosition(int x,int y);
  
   sf:: Vector2f getPosition();
    sf::Vector2u size = texture.getSize();
  
   

};




