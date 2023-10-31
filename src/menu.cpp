#include"menu.hpp"
#include"menu1.hpp"
#include"maincharacter.hpp"
menu::menu(data* data): _data(data){}
menu::~menu(){}
void menu::init()
{
    _data->_assets->addTexture(BACKGROUND, "resources//background.png");
    background.setTexture(&_data->_assets->getTexture(BACKGROUND));
   
    background.setSize(sf::Vector2f(1920,1080));
    background.setFillColor(sf::Color::White);
}
void menu::processInput()
{
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
void menu::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _data->_states->addState(new menu1(_data));
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        _data->_states->addState(new maincharacter(_data));
    }

}

void menu::draw(){
   _data->_window->clear();
   // _data->_window->draw(background);
    _data->_window->draw(background);
    _data->_window->display();
}