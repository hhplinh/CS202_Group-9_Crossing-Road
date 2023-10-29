#include<iostream>
#include"GameMap.hpp"
#include<SFML/Graphics.hpp>
#include"player.hpp"

class game
{
    private :
     sf :: RenderWindow *window; 
    player player1;
    gameWorld gameWorld1;
    bool end;
    sf:: VideoMode videomode;
    sf::Event ev;
    void initvariables();

    void initwindow();
    public:
    void update();
    void render();
    game ();
    ~game();
    void pollEvents();
    const bool running() const;

};