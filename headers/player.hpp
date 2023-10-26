#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class player
{  

    private :
    sf :: RectangleShape shape;
    void initvariables();
    
    void initshape();
     public :
    Texture texture;
    Sprite p;

    void LoadContent(string path);
 
    void drawchar(RenderWindow &window);
    void update();
    void render(sf:: RenderTarget *target );  
    
    player(string path);
    
   
    void move();
 
    void setPosition(int x,int y);
  
    Vector2f getPosition();
  
   

};




