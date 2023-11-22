#include "loadMapLevel.hpp"

void mapeasyLoad::init()
{

  background.setSize(sf::Vector2f(1920, 1080));
  background.setFillColor(sf::Color::White);

  maincharactereasy *p1 = new maincharactereasy(_data);
  this->player = p1;
  this->player->init();
  this->blocks.clear();

  this->river.clear();
  this->length = 10;

  if (_data->_assets->isGameSaved() == true)
  {
    loadGame();
    return;
  }

  pos1.x = 0;
  pos1.y = 906;
  this->currentIndex = 0;

  this->createmap();
}


void mapLoad::init()
{ // do not init if resume from pause menu
  // check the state size
  // using state machine size
  background.setSize(sf::Vector2f(1920, 1080));
  background.setFillColor(sf::Color::White);

  player = new maincharacter(_data);
  player->init();
  this->blocks.clear();

  this->river.clear();
  this->length = 10;

  if (_data->_assets->isGameSaved() == true)
  {
    loadGame();
    return;
  }

  // set player position to the bottom of the screen
  pos1.x = 0;
  pos1.y = 906;

  this->currentIndex = 0;
  createmap();
}

