#include"map.hpp"
#include<iostream>
#include<random>
void map::init()
{  player = new maincharacter(_data);
    player->init();
    

    //set player position to the bottom of the screen
    
    this->length = 10;
    createmap();
    background.setSize(sf::Vector2f(1920,1080));
    background.setFillColor(sf::Color::White);
}
void map::processInput()
{  // sf::Event event;
	//while (_data->_window->pollEvent(event))
	//{
		//switch (event.type)
		//{
		//case sf::Event::Closed:
		//	_data->_window->close();
		//	break;
       // }
    //}
    player->processInput();
}
void map::update()
{
    player->update();
    std:: cout<< blocks.size()<<std::endl;
    // Check if the character has reached 0.75 * height of the screen
    float characterY = player->getPosition().y;
    float screenHeight = _data->_window->getSize().y;

    if (characterY > 0.75 * screenHeight&& characterY<0.8*screenHeight)
    {
        // Add more blocks when the character is close to the top
       createmap();
       std::cout<<blocks.size()<<std::endl;
    }
     sf::Vector2f screenSize(1920, 1080); // Adjust this based on your screen size
      for (auto it = blocks.begin(); it != blocks.end();)
    {
        sf::Vector2f blockPosition = (*it)->getpos();
        sf::Vector2u blockSize = _data->_assets->getTexture(ROAD).getSize();

        if (blockPosition.y > screenHeight)
        {
            // Block is below the screen, delete it
            delete *it;
            it = blocks.erase(it);
        }
        else
        {
            ++it;
        }
    }
}





void map::draw()
{  
    _data->_window->clear();
   
    _data->_window->draw(background);
    sf:: Vector2f pos(0,1080-174);
    //increase the y coordinate of the block so that it would nt be overlapped
    //posy sould += the the height of the block
    // we should find the height first


    //find the height of block texture by get the texture of road png
    sf::Vector2u sizeBlock =  _data->_assets->getTexture(ROAD).getSize();
  
// generate the block to fill the screen with the road is at bottom  and then all random


for (int i = 0; i < blocks.size(); i++) {
    blocks[i]->setpos(pos);
    blocks[i]->draw();
    pos.y -= sizeBlock.y;
    
}  
//set player position to the bottom of the screen
    std::cout<<blocks.size()<<std::endl;
    player->draw();
    _data->_window->display();

}
void map::createmap()
{
    addblock("road");
    addblock("river");
    addblock("grass");
    int z;
    for(int i=0;i<length;i++)
    {    z=rand()%3;
        if(z==0)
        {
            addblock("road");
        }
        else if(z==1)
        {
            addblock("grass");
        }
        else if(z==2)
        {
            addblock("river");
        }
    }
   
    

     //   blocks[0]->draw();
        
    
}
void map::addblock( std:: string terrainName )
{   block * newblock = new block(_data);
    sf::Vector2f pos(0,0);
    newblock->init(terrainName , pos, true , false);
    blocks.push_back(newblock);

}
map :: map( data* data)
{
    _data = data;
}