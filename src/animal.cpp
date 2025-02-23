#include "Animal.hpp"
Animal ::Animal(data *_data) : _data(_data)
{
  // this->init();
  int z;

  z = rand() % 2;
  if (z == 1)
  {
    this->goR = true;
    // this-> sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
    this->sprite.setPosition(0, 0);
  }
  else
  {
    this->goR = false;
    //  this-> sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
    this->sprite.setPosition(1000, 0);
  }
}
void Animal::setposAnimal(sf::Vector2f posblock)
{
  sprite.setPosition(posblock.x, posblock.y);
}

void Animal ::AnimalTurn()
{
  this->goR = !goR;
}

void Animal::setGoR(bool _gor)
{
  this->goR = _gor;
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}

std::string Animal ::getAnimalName()
{
  return this->name;
}

void Animal ::AnimalRun()
{
  if (frameTimer.getElapsedTime() >= frameDuration)
  {
    // Reset the frame timer
    frameTimer.restart();

    // Update the x position of the texture rectangle for the animation frame
    int xtexture = (sprite.getTextureRect().left + size.x) % (size.x * col);

    // Update the y position of the texture rectangle based on the direction
    int ytexture = this->goR ? 0 : size.y;

    // Set the texture rectangle to display the correct frame
    sprite.setTextureRect(sf::IntRect(xtexture, ytexture, size.x, size.y));
  }

  // Move the sprite based on the direction
  float xMovement = this->goR ? speed : -speed;
  sprite.move(xMovement, 0);
}
void Animal ::init()
{

  int z;

  z = rand() % 2;
  if (z == 1)
  {
    this->goR = true;
    // this-> sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
    this->sprite.setPosition(0, 0);
  }
  else
  {
    this->goR = false;
    //  this-> sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
    this->sprite.setPosition(1000, 0);
  }
}
cop ::cop(data *_data) : Animal(_data)
{

  this->name = "cop";
  this->row = 2;
  this->col = 10;
  this->speed = 5;
  this->size = _data->_assets->getTexture(COP).getSize();
  this->size.x /= col;
  this->size.y /= row;
  this->sprite.setTexture(_data->_assets->getTexture(COP));
  // this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}
gau ::gau(data *_data) : Animal(_data)
{
  this->name = "gau";
  this->row = 2;
  this->col = 10;
  this->speed = 5;
  this->size = _data->_assets->getTexture(GAU).getSize();
  this->size.x /= col;
  this->size.y /= row;
  this->sprite.setTexture(_data->_assets->getTexture(GAU));
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}

tegiac ::tegiac(data *_data) : Animal(_data)
{
  this->name = "tegiac";
  this->row = 2;
  this->col = 10;
  this->speed = 5;
  this->size = _data->_assets->getTexture(TEGIAC).getSize();
  this->size.x /= col;
  this->size.y /= row;
  this->sprite.setTexture(_data->_assets->getTexture(TEGIAC));
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}
voi ::voi(data *_data) : Animal(_data)
{
  this->name = "voi";
  this->row = 2;
  this->col = 10;
  this->speed = 5;
  this->size = _data->_assets->getTexture(VOI).getSize();
  this->size.x /= col;
  this->size.y /= row;
  this->sprite.setTexture(_data->_assets->getTexture(VOI));
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}
lacda ::lacda(data *_data) : Animal(_data)
{
  this->name = "lacda";
  this->row = 2;
  this->col = 10;
  this->speed = 5;
  this->size = _data->_assets->getTexture(LACDA).getSize();
  this->size.x /= col;
  this->size.y /= row;
  this->sprite.setTexture(_data->_assets->getTexture(LACDA));
  if (this->goR)
  {
    this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
  }
  else
  {
    this->sprite.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
  }
}

void Animal::setSpeed(float _speed)
{
  speed = _speed;
}

float Animal::getSpeed()
{
  return speed;
}