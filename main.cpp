#include <SFML/Graphics.hpp>
#include"player.hpp"
#include"MAINMENU.h"
#include"terrain.hpp"
#define WIDTH 1920
#define HEIGHT 1080
using namespace std;
int main() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML works!");
    window.setFramerateLimit(60);
    player p1("resources/orge.png");
    p1.setPosition(WIDTH/2,HEIGHT/2);
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        p1.move();
        window.clear(Color ::White);
        p1.draw(window);
        window.display();
    }
    return 0;
}
//     }