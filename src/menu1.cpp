#include"menu1.hpp"
#include"menu.hpp"
menu1::menu1(data* data): _data(data){}
menu1::~menu1(){}
void menu1::init(){
    background.setSize(sf::Vector2f(800,600));
    background.setFillColor(sf::Color::Blue);
}
void menu1::processInput(){
    sf::Event event;
	while (_data->_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			_data->_window->close();
			break;
        }
    }
    
}
void menu1::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        _data->_states->removeState();
    }
}

void menu1::draw(){
   _data->_window->clear();
    _data->_window->draw(background);
    _data->_window->display();
}