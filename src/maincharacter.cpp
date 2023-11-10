#include"maincharacter.hpp"
#include"menu.hpp"
void maincharacter::init()
{
    _data->_assets->addTexture(PLAYER, "resources//orge.png");

    row = 4;
    col = 4;
    size = _data->_assets->getTexture(PLAYER).getSize();
    p.setTexture(_data->_assets->getTexture(PLAYER));
    p.setPosition(1920 / 2 + size.x / col, 1080 - size.y / row);

    velocity.x = 0;
    velocity.y = 0;

    size.x = size.x / col;
    size.y = size.y / row;

    p.setTextureRect(sf::IntRect(0, size.y * 3, size.x, size.y));

    // Set the initial view size to the size of the window
    camera.setSize(1920, 1080);

    // Center the camera on the player
    camera.setCenter(1920 / 2, 1080 / 2);

    // Set the initial view to the camera
    _data->_window->setView(camera);

    mApressed = false;
}



maincharacter::maincharacter(data* data): _data(data){}

void maincharacter::draw()
{
 
 
 //_data->_window->clear();

   
    _data->_window->draw(p);
  // _data->_window->display();
}

void maincharacter::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * col);
        p.setTextureRect(sf::IntRect(xtexture, size.y * 2, size.x, size.y));
        p.move(10, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * col);
        p.setTextureRect(sf::IntRect(xtexture, size.y * 3, size.x, size.y));
        p.move(0, -10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * col);
        p.setTextureRect(sf::IntRect(xtexture, size.y, size.x, size.y));
        p.move(-10, 0);
    }
   /*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        int ytexture = (p.getTextureRect().top + size.y) % (size.y * row);
        p.setTextureRect(sf::IntRect(0, ytexture, size.x, size.y));
        p.move(0, 2);
    }*/
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
        //popstate //change to is key release

      else if( sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
         mApressed = true;
        }
       
    }
}
void maincharacter::update()
{
    if (mApressed)
    {
        mApressed = false;
        _data->_states->removeState();
    }

    this->move();

    // Update the camera to follow the character vertically
    camera.setCenter(1920 / 2, p.getPosition().y);

    // Set the view to the camera
    _data->_window->setView(camera);
}