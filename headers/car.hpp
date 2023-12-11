#include "enemy.hpp"
#include <random>
#include "system.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class car : public sf::Drawable
{
protected:
  bool istoright = true;
  float speed;
  data *_data;
  sf ::Sprite sprite;
  int row, col;


    sf::Vector2u size;
    

public:
  std::string getCarType()
  {
    if (sprite.getTexture() == &_data->_assets->getTexture(CAR))
    {
      return "CAR";
    }
    else if (sprite.getTexture() == &_data->_assets->getTexture(CAR2))
    {
      return "CAR2";
    }
    else if (sprite.getTexture() == &_data->_assets->getTexture(CAR3))
    {
      return "CAR3";
    }
    else if (sprite.getTexture() == &_data->_assets->getTexture(CAR4))
    {
      return "CAR4";
    }
    else if (sprite.getTexture() == &_data->_assets->getTexture(CAR5))
    {
      return "CAR5";
    }
    else
    {
      return "CAR";
    }
  }

  bool isRight() { return istoright; }
  void setGoR(bool istoright) { this->istoright = istoright; }
  sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }
  void setposcar(sf::Vector2f posblock) { sprite.setPosition(posblock.x, posblock.y); }
  void turnaround()
  {
    this->istoright = !istoright;
  }
  void draw(sf::RenderTarget &target, sf::RenderStates states) const
  {
    target.draw(sprite);
  }
  void setspeed(float speed) { this->speed = speed; }

  float getspeed() { return this->speed; }
  void run()
  {

    if (istoright == true)
    { this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y)); 
      sprite.move(speed, 0);
    }
    else
    {this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y)); 
      sprite.move(-speed, 0);
    }
}

  
  sf::Vector2f getposcar() 
  { return sprite.getPosition(); }
  car(data *_data) : _data(_data)
  {
    //sprite.setTexture(_data->_assets->getTexture(CAR));
    // resize the car to fit the road
    this->row=2;
    this->col=1;
   this->size = _data->_assets->getTexture(CAR2).getSize();
    this->size.x = this->size.x / col;
    this->size.y = this->size.y / row;
    sprite.setScale(0.5, 0.5);
    int z;
    this->speed = 30;
    z = rand() % 2;
    if (z == 1)
    {
      this->istoright = true;
      this->sprite.setPosition(0, 0);
    }
    else
    {
      this->istoright = false;
      this->sprite.setPosition(1000, 0);
    }
  }
  sf::Sprite getSprite() 
  { return sprite; }
};
class car2 : public car
{
public:
  car2(data *_data) : car(_data)
  {
    this->sprite.setTexture(_data->_assets->getTexture(CAR2));
 
  }
};
class car3 : public car
{
public:
  car3(data *_data) : car(_data)
  {
   this->sprite.setTexture(_data->_assets->getTexture(CAR3));

  }
};
class car4 : public car
{
public:
  car4(data *_data) : car(_data)
  {
  this->sprite.setTexture(_data->_assets->getTexture(CAR4));

  }
};
class car5 : public car
{
public:
  car5(data *_data) : car(_data)
  {
this->sprite.setTexture(_data->_assets->getTexture(CAR5));

  }
};
