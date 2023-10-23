#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class player
{
     public :
    Texture texture;
    Sprite p;

    void LoadContent(string path);
 
    void draw(RenderWindow &window);
  
    
    player(string path);
  
   
    void move();
 
    void setPosition(int x,int y);
  
    Vector2f getPosition();
  
   

};




