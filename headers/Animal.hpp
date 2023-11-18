#include"enemy.hpp"
#include<random>
#include "system.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Animal : public sf::Drawable
{
    private :
    bool istoright=true;
    float speed;
    data * _data;
    sf::Sprite sprite;
    sf::Vector2u size ;
    sf::Texture texture;
    int col;
    public :
    void foo()
    {
     
    }
    sf :: FloatRect getGlobalBounds(){return sprite.getGlobalBounds();}
    void setposanimal( sf::Vector2f posblock){ sprite.setPosition( sprite.getPosition().x , posblock.y );}
    void turnaround()
    { istoright=!istoright;
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }
    void setspeed(float speed){this->speed=speed;}
    
    float getspeed(){return this->speed;}
    void run()
    { 
      
      if( istoright==true)
      {
          sprite.move(speed,0);
          
      }
      else
      {
          sprite.move(-speed,0);
      }

    }
    sf::Vector2f getposanimal(){return sprite.getPosition();}
    Animal(data* _data) : _data(_data)
    {
      int category = rand()%5; //0-Gau,1-Voi,2-Cop,3-Lacda,4-Tegiac
      switch (category)
      {
      case 0: 
        col = 10;
        size = _data->_assets->getTexture(GAU).getSize();
        this->sprite.setTexture(_data->_assets->getTexture(GAU));
        sprite.setTextureRect(sf::IntRect(0, 0, size.x / col, size.y));
        break;
      
      case 1:
        col = 12;
        size = _data->_assets->getTexture(VOI).getSize();
        this->sprite.setTexture(_data->_assets->getTexture(VOI));
        sprite.setTextureRect(sf::IntRect(0, 0, size.x / col, size.y));
        break;
      case 2:
        col = 17;
        size = _data->_assets->getTexture(COP).getSize();
        this->sprite.setTexture(_data->_assets->getTexture(COP));
        sprite.setTextureRect(sf::IntRect(0, 0, size.x / col, size.y));
        break;
      case 3: 
        col = 14;
        size = _data->_assets->getTexture(LACDA).getSize();
        this->sprite.setTexture(_data->_assets->getTexture(LACDA));
        sprite.setTextureRect(sf::IntRect(0, 0, size.x / col, size.y));
        break;
      case 4:
        col = 12;
        size = _data->_assets->getTexture(TEGIAC).getSize();
        this->sprite.setTexture(_data->_assets->getTexture(TEGIAC));
        sprite.setTextureRect(sf::IntRect(0, 0, size.x / col, size.y));
        break;
      }
      
     
    int z;
    this->speed=3;
      z= rand()%2;
      if ( z==1)
      {
            this->istoright=true;
          this->sprite.setPosition(1000,0);
        }
        else
        {
            this->istoright=false;
        this ->sprite.setPosition(1000,0);
        }
      
      }
      };
