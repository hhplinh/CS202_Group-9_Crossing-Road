#include"map.hpp"
#include "maincharactereasy.hpp"
class mapeasy : public map
{
  private :
  
  public:
  mapeasy( data * _data):map(_data)
  {   
  }
  void init()
  {
  
    pos1.x = 0;
    pos1.y = 906;
    maincharactereasy *p1 = new maincharactereasy(_data);
    this->player = p1;
  
    this->player->init();
    this->blocks.clear();

    this->currentIndex = 0;

    this->river.clear();
    this->length = 10;
    this->createmap();
   
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);
}
  };