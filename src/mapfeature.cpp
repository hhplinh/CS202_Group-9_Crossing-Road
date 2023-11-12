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
    this->isPassable=true;
 }
    if(terrainName == "river")
    {
    
    sprite.setTexture( _data->_assets->getTexture(RIVER));
    sprite.setPosition(pos);
    this->isPassable=false;
    }
      if(terrainName == "grass")
      {
          
      sprite.setTexture( _data->_assets->getTexture(GRASS));
      sprite.setPosition(pos);
      this->isPassable=true;
      
      }
}
void block::draw()
{
   
    _data->_window->draw(sprite);
}
void block::update()
{
    
}
void block::setpos( sf::Vector2f posblock)
{
    sprite.setPosition(posblock);
}
void block::processInput()
{
    
}

block :: block( )
{
   
    
}