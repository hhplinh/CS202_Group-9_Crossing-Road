#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class player
{
    private :
    Texture texture;
    Sprite sprite;
    public :
    player(){}
    player(string path)
    {
      if( !texture.loadFromFile(path)) cout<<" can't load player texture"<<endl;
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
        sprite.setScale(0.5, 0.5);
    }
    void draw(RenderWindow &window)
    {
        window.draw(sprite);
    }
    void move(char direction , float speed)
    {
        if(direction == 'u')
        {
            sprite.move(0,-speed);
        }
        else if(direction == 'd')
        {
            sprite.move(0,speed);
        }
        else if(direction == 'l')
        {
            sprite.move(-speed,0);
        }
        else if(direction == 'r')
        {
            sprite.move(speed,0);
        }
    }
};




