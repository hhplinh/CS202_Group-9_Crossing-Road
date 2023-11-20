#include"enemy.hpp"
#include<random>
#include "system.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Animal : public sf::Drawable
{
  protected :
  data * _data;
  float speed;
  int row , col;
  bool goR;
  
  sf:: Sprite sprite;
  sf:: Texture texture;

  public:
   virtual ~Animal() {}
  sf::Vector2f getposAnimal(){return this->sprite.getPosition();}
  Animal(data* _data) : _data(_data)
  {
  this->init();
  }
  void setposAnimal( sf::Vector2f posblock);
  void init();
  void draw( sf::RenderTarget& target, sf::RenderStates states) const;
  void AnimalTurn();
  sf::Vector2u size;
  void AnimalRun()
  {
    if(goR==true)
    { // int xtexture = (sprite.getTextureRect().left + size.x) % (size.x * col);
     // sprite.setTextureRect(sf::IntRect(xtexture, size.y * 2, size.x, size.y));
     
       
      sprite.move(speed,0);
    }
    else
    { 
      //int xtexture = (sprite.getTextureRect().left + size.x) % (size.x * col);
    //sprite.setTextureRect(sf::IntRect(xtexture, size.y * 3, size.x, size.y));
     sprite.move(-speed,0);
    }
  }
  
  
};
class cop : public Animal
{
  public:
  ~cop() {}
  cop(data* _data) : Animal(_data)
  {
  
  
  this-> row =4;
  this->col=4;
  this->speed=0.5;
  this->size = _data->_assets->getTexture(ORGE).getSize();
   
  this->sprite.setTexture( _data->_assets->getTexture(ORGE));
  this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));

  }
 


};
class tegiac : public Animal
{

};
class lacda : public Animal
{

};
class voi : public Animal
{

};
class gau : public Animal
{
  
};
