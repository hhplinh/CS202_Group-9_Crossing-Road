#include"maincharacter.hpp"
#include"menu.hpp"
void maincharacter::init()
{
    _data->_assets->addTexture(PLAYER,"resources//orge.png");
   // texture = _data->_assets.getTexture(PLAYER);
     size=_data->_assets->getTexture(PLAYER).getSize();
    p.setTexture(_data->_assets->getTexture(PLAYER));
    p.setPosition(0,0);
      p.setTextureRect(sf::IntRect(0,0,size.x,size.y));
    velocity.x = 0;
    velocity.y = 0;
    row = 4;
    col = 4;
    size.x=size.x/col;
    size.y=size.y/row;
        p.setTextureRect(sf::IntRect(0,0,size.x,size.y));
   // size=_data->_assets->getTexture(PLAYER).getSize();

}
maincharacter::maincharacter(data* data): _data(data){}
void maincharacter::draw()
{
 _data->_window->clear();
   // _data->_window->draw(background);
   
    _data->_window->draw(p);
    _data->_window->display();
}

void maincharacter ::move()
{   
        size.x /=4;
        size.y /=4;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {  
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y*2,size.x,size.y));
        p.move(0.5,0);
        


        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {  p.setTextureRect(sf::IntRect(size.x*3,size.y*3,size.x,size.y));

        int xtexture=0;
        xtexture=(int)getPosition().y/60%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y*3,size.x,size.y));
        p.move(0,-0.5);

        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {  
        p.setTextureRect(sf::IntRect(size.x*3,size.y,size.x,size.y));
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y,size.x,size.y));
        p.move(-0.5,0);


        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {  
        
        p.setTextureRect(sf::IntRect(0,0,size.x,size.y));

        int ytexture=0;
        ytexture=(int)getPosition().y/20%4;
        ytexture*=size.x;

        p.setTextureRect(sf::IntRect(ytexture,0,size.x,size.y));

        p.move(0,0.5);

        
        }

}
sf::Vector2f maincharacter::getPosition()
{
    p.getPosition();
    return p.getPosition();
}
void maincharacter::setPosition(int x,int y)
{
    p.setPosition(x,y);
}
void maincharacter::processInput()
{
    sf::Event event;
    while(_data->_window->pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            _data->_window->close();
        }
        move();
    }
}
void maincharacter::update()
{
    move();
}
