#include"Animal.hpp"
 Animal :: Animal(data* _data) : _data(_data)
  {
  this->init();
  }
void Animal:: setposAnimal(sf::Vector2f posblock)
{
    sprite.setPosition( this->sprite.getPosition().x , posblock.y );
}

void Animal :: AnimalTurn()
{ 
    this->goR=!goR;

}
   
  void Animal :: AnimalRun()
  {
    if(goR==true)
    {  int xtexture = (sprite.getTextureRect().left + size.x) % (size.x * col);
      sprite.setTextureRect(sf::IntRect(xtexture, 0, size.x, size.y));
     
       
     this-> sprite.move(speed,0);
    }
    else
    { 
      int xtexture = (sprite.getTextureRect().left + size.x) % (size.x * col);
    sprite.setTextureRect(sf::IntRect(xtexture, size.y , size.x, size.y));
     this->sprite.move(-speed,0);
    }
  }
  
void Animal :: init()
{
 
    int z;
    this->speed=30;
      z= rand()%2;
      if ( z==1)
      {
            this->goR=true;
          //  this-> sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
          this->sprite.setPosition(0,0);
        }
        else
        {
            this->goR=false;
           // this-> sprite.setTextureRect(sf::IntRect(0, 1, size.x, size.y));
        this ->sprite.setPosition(1000,0);
        }

}
  cop :: cop(data* _data) : Animal(_data)
  {
  
  
 this-> row =2;
  this->col=17;
  this->speed=20;
  this->size = _data->_assets->getTexture(COP).getSize();
   this->size.x/=col;
    this->size.y/=row;
  this->sprite.setTexture( _data->_assets->getTexture(COP));
 

  }