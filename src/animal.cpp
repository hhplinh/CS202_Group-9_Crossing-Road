#include"Animal.hpp"

void Animal:: setposAnimal(sf::Vector2f posblock)
{
    sprite.setPosition( sprite.getPosition().x , posblock.y );
}
void Animal :: draw ( sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}   
void Animal :: AnimalTurn()
{ 
    this->goR=!goR;

}
void Animal :: init()
{
    size.x /= col;
  size.y /= row;
    int z;
    this->speed=30;
      z= rand()%2;
      if ( z==1)
      {
            this->goR=true;
            this-> sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
          this->sprite.setPosition(0,0);
        }
        else
        {
            this->goR=false;
            this-> sprite.setTextureRect(sf::IntRect(0, 1, size.x, size.y));
        this ->sprite.setPosition(1000,0);
        }

}