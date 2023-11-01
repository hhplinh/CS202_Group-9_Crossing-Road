#include"map.hpp"
#include<iostream>
void map::init()
{
    createmap();
    background.setSize(sf::Vector2f(1920,1080));
    background.setFillColor(sf::Color::White);
}
void map::processInput()
{   sf::Event event;
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
void map::update()
{
     // std::cout<<"map init"<<std::endl;
}
void map::draw()
{  

    
}
void map::createmap()
{
    addblock("road");
    addblock("river");
    std::cout<<blocks.size()<<std::endl;
   
     //   blocks[0]->draw();
        
    
}
void map::addblock( std:: string terrainName )
{   block * newblock = new block;
sf::Vector2f pos(0,0);
    newblock->init(terrainName , pos, true , false);
    blocks.push_back(newblock);

}
map :: map( data* data)
{
    _data = data;
}