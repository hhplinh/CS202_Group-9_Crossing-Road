#include "enemy.hpp"
#include <random>
#include "system.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class car : public sf::Drawable
{
private:
  bool istoright = true;
  float speed;
  data *_data;
  sf ::Sprite sprite;

public:
  void foo()
  {
  }
  sf ::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }
  void setposcar(sf::Vector2f posblock) { sprite.setPosition(sprite.getPosition().x, posblock.y); }
  void turnaround()
  {
    istoright = !istoright;
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
    {
      sprite.move(speed, 0);
    }
    else
    {
      sprite.move(-speed, 0);
    }
  }
  sf::Vector2f getposcar() { return sprite.getPosition(); }
  car(data *_data) : _data(_data)
  {
    sprite.setTexture(_data->_assets->getTexture(CAR));

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
  sf::Sprite getSprite() { return sprite; }
};
