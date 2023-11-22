#include "map.hpp"
#include "maincharactereasy.hpp"
#include <fstream>
class mapeasy : public map
{
private:

public:
  mapeasy(data *_data) : map(_data)
  {
  }

  void init()
  {

    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);

    maincharactereasy *p1 = new maincharactereasy(_data);
    this->player = p1;
    this->player->init();
    this->blocks.clear();

    this->river.clear();
    this->length = 10;

    pos1.x = 0;
    pos1.y = 906;
    this->currentIndex = 0;

    this->createmap();
  }

  bool isEasy()
  {
    return 1;
  }

};