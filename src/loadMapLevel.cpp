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

    //cerr all size of vectors to debug
    std::cerr << "blocks size: " << blocks.size() << std::endl;
    std::cerr << "currentIndex: " << currentIndex << std::endl;
    //animal, car, cano
    std::cerr << "animal size: " << enemies.size() << std::endl;
    std::cerr << "car size: " << enemies2.size() << std::endl;

    std::cerr << "pos1.x: " << pos1.x << std::endl;
    std::cerr << "pos1.y: " << pos1.y << std::endl;
    std::cerr << "length: " << length << std::endl;
    std::cerr << "player->getPos().x: " << player->getPosition().x << std::endl;
    std::cerr << "player->getPos().y: " << player->getPosition().y << std::endl;

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

void mapLoad::draw()
{
  std::cerr << "draw" << std::endl;
  drawTemplate();
  if (isCountdownScreenNeeded == true)
  {
    _data->_window->setView(_data->_window->getDefaultView());
    loadCountdownScreen();
    isCountdownScreenNeeded = false;
  }
  _data->_window->display();

}

void mapeasyLoad::draw()
{
  std::cerr << "draw" << std::endl;
  drawTemplate();
  if (isCountdownScreenNeeded == true)
  {
    _data->_window->setView(_data->_window->getDefaultView());
    loadCountdownScreen();
    isCountdownScreenNeeded = false;
  }
  _data->_window->display();


}