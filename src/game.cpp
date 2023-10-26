#include"game.hpp"
game ::~game ()
{ delete this->window;


}
game::game() : player1("resources/orge.png") {
    // Constructor implementation for game
    this->initwindow();
    this->initvariables();
}

void game :: initvariables()
{
    this->end = false;
}

void game :: initwindow()
{
    this-> videomode = sf:: VideoMode(800,600);
    this-> window = new sf :: RenderWindow( this->videomode,"CrossyRoad",sf::Style::Titlebar | sf::Style::Close);
}
const bool game :: running() const
{
    return this->window->isOpen();
}
void game::pollEvents()
{
    while(this->window ->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                    break;
                }
        }
    }
}
void game :: render()
{   
    this->window->clear();
    this->player1.render(this->window);
    this->player1.move();
    this->window->display();
}
void game :: update()
{
    this->pollEvents();
    this->render();
}