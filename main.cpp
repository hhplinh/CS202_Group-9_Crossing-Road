/*#include <SFML/Graphics.hpp>
#include"player.hpp"
#include"MAINMENU.h"
#include"terrain.hpp"
#define WIDTH 1280
#define HEIGHT 720
#include<iostream>
#include<ctime>
#include"game.hpp"
#include"GameMap.hpp"
#include"TerrainBlock.hpp"
using namespace std;

int main() 
{
 srand (static_cast <unsigned>(time(0)));
  game game1;

  while( game1.running())
  { game1.update();
    game1.render();
    
    game1.pollEvents();
    game1.render();    

  }


}*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}



// #include "system.h"
// int main()
// {
//   System system;
//   return 0;
// }