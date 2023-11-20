#include <SFML/Graphics.hpp>
#include"system.h"
#include <iostream>
#pragma once
class trafficlight : public sf::Drawable
{
private:
data *_data;
bool isRed, isGreen;
sf::Clock timer;
sf :: Sprite sprite;
sf :: Texture texture;
int row , col;

public:
sf:: Vector2u size;
void setpos(float y)
{
    //change sprite pos y
    sprite.setPosition(0,y);
}
bool carCanGo()
{
  return isGreen;

}
trafficlight(data* _data) : _data(_data) { init(); }
void init()
{   this -> row =1;
    this -> col =2;
       size = _data->_assets->getTexture(TRAFFICLIGHT).getSize();
    this->size.x /= col;
    this->size.y /= row;
       this->isGreen = true;
    sprite.setTexture(_data->_assets->getTexture(TRAFFICLIGHT));
     sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));


   
  



}
void draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}
void turnOnRed()
{
   
        isGreen = false;
        isRed = true;
        sprite.setTextureRect(sf::IntRect(size.x, 0, size.x, size.y));

    

}
void turnOnGreen()
{
    
        isGreen = true;
        isRed = false;
        sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
     
    
}
void turn()
{
    if (timer.getElapsedTime().asSeconds() > 5)
    {
        if (isGreen)
        {
            turnOnRed();
            timer.restart();
        }
        else if (isRed)
        {
            turnOnGreen();
            timer.restart();
        }
    }
}
};