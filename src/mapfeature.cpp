#include"mapfeature.hpp"

void block::init( std:: string terrainName  , sf::Vector2f pos ,bool isPassable , bool isExit )
{
 

 this-> isPassable = isPassable;
this-> isExit = isExit;
    

   this-> terrainName = terrainName;
if(terrainName == "road")
 {  
    sprite.setTexture( _data->_assets->getTexture(ROAD));
    sprite.setPosition(pos);
 }
    if(terrainName == "river")
    {
    
    sprite.setTexture( _data->_assets->getTexture(RIVER));
    sprite.setPosition(pos);
    }
}
void block::draw()
{
    
    _data->_window->draw(sprite);
}
void block::update()
{
    
}
void block::processInput()
{
    
}

block :: block( )
{
   
    
}