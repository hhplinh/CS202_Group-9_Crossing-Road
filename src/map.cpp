#include "map.hpp"

#include "menuPause.hpp"
#include "endgameMenu.hpp"
#include "maincharacter.hpp"

void map::init()
{ // do not init if resume from pause menu
  // check the state size
    // using state machine size
 pos1.x = 0;
    pos1.y = 906;
    player = new maincharacter(_data);
    player->init();
    this->blocks.clear();

    this->currentIndex = 0;
    // set player position to the bottom of the screen
    this->river.clear();
    this->length = 10;
    createmap();
   
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);
}
void map::processInput()
{
    sf::Event event;

   while (_data->_window->pollEvent(event))
   {    player->processInput(event);
         if (event.type == sf::Event::Closed)
         {
              _data->_window->close();
         }

         if (event.type == sf::Event::KeyPressed)
         {
              if (event.key.code == sf::Keyboard::Escape)
              {
                mescpressed = true;
            }
        }
    }
}
void map::update()
{
    float prePos = player->getPosition().y;
    player->update();
    float pos = player->getPosition().y;

    float i = ( pos/1080.0 +1);
   
    float j=-i;
    int k= int (i);
    int f= int (j);
    if( pos>0)
    {      currentIndex = 0;
    }
      else
    {
        currentIndex =( int((pos)/-1080.0) )*6;
    }
     float o= pos/-1080.0-int((pos)/-1080);
     std::cout<<o<<std::endl;
    if( (((pos/1080.0)<0.1&& pos>0&&(blocks.size() - currentIndex < 15))||(o<0.9&&pos<0&& (blocks.size() - currentIndex < 50))))
    
    
    {   
        int z;
        for( int i=0;i<1;i++)
        {  z = rand() % 3;

            if (z == 0)
            {
                addedroad = true;
                addblock("road");
            }
            else if (z == 1)
            { addedgrass = true;
                addblock("grass");
            }
            else if (z == 2)
            {
                addedRiver = true;
                addblock("river");
            }
        }
    }
   

  

    river.clear();

    for (int i = currentIndex; i < blocks.size(); i++)
    {
       

        if (blocks[i]->getTerrainName() == "river")
        {
            if (addedRiver == true && newRiverIdx == i)
            {
                riverPos.push_back(blocks[i]->getpos());
                addedRiver = false;
                Cano *newCano = new Cano(_data);
                enemies2.push_back(newCano);
                enemies2[enemies2.size() - 1]->setPosCano(sf::Vector2f(riverPos.back().x, riverPos.back().y - 30));
            }
        }
        else if (blocks[i]->getTerrainName() == "road")
        {
            if (addedroad == true && newRoadIdx == i)
            {
                roadpos.push_back(blocks[i]->getpos());
                addedroad = false;
                car *newcar = new car(_data);
                trafficlight *newtrafficlight = new trafficlight(_data);
                enemies.push_back(newcar);
                enemies[enemies.size() - 1]->setposcar(sf::Vector2f(roadpos.back().x, roadpos.back().y + 50));
                trafficlights.push_back(newtrafficlight);
                trafficlights[trafficlights.size() - 1]->setpos(roadpos.back().y );
            }
        }
        else if( blocks[i]->getTerrainName() == "grass")
        {
           if (addedgrass == true && newGrassIdx == i)
            {
                grasspos.push_back(blocks[i]->getpos());
                addedgrass = false;
               Animal *a = new cop (_data);
                

              animals.push_back(a);
              animals[animals.size() - 1]-> setposAnimal(sf::Vector2f(grasspos.back().x, grasspos.back().y + 50));
                
            }
        }
       
    }
    

  
   
    for (int i = 0; i < enemies.size(); i++)
    {
       if( trafficlights[i]->carCanGo()) 
       {
        enemies[i]->run();
      

 
       }
        if (enemies[i]->getposcar().x > 1920 || enemies[i]->getposcar().x < 0)
        {
            enemies[i]->turnaround();
        }
       
    }
    // run the cano
    for (int i = 0; i < enemies2.size(); i++)
    {
        enemies2[i]->floatOnRiver();
        if (enemies2[i]->getPosCano().x > 1920 || enemies2[i]->getPosCano().x < 0)
        {
            enemies2[i]->turnAround();
        }
    }
    for ( int i=0;i<animals.size();i++)
    { std:: cout<< animals.size();
        animals[i]->AnimalRun();
        if (animals[i]->getposAnimal().x > 1920 || animals[i]->getposAnimal().x < 0)
        {
            animals[i]->AnimalTurn();
        }
    }

    if (mescpressed == true)
    {
        backgroundTexture.create(_data->_window->getSize().x, _data->_window->getSize().y);
        auto& window = static_cast<sf::RenderWindow&>(*(_data->_window));
        backgroundTexture.update(window);
        _data->_assets->setBackgroundTexture(backgroundTexture);
        
        mescpressed = false;
        _data->_window->setView(_data->_window->getDefaultView());
        _data->_states->addState((new menuPause(_data)), false);
    }
    for( int i=0;i<trafficlights.size();i++)
    {
        trafficlights[i]->turn();
    }
   std:: cout<<"current block : "<<this-> currentIndex<< " : "<<this-> blocks.size()<<std::endl;
}

void map::draw()
{
    _data->_window->clear();

    _data->_window->draw(background);

    for (int i = currentIndex; i < blocks.size(); i++)
    {
        // blocks[i]->setpos(pos);
        blocks[i]->draw();
    }
    // draw the car
    for (int i = 0; i < enemies.size(); i++)
    {
        _data->_window->draw(*enemies[i]);
    }
    for( int i=0;i<trafficlights.size();i++)
    {
        _data->_window->draw(*trafficlights[i]);
    }
    // draw the cano
    for (int i = 0; i < enemies2.size(); i++)
    {
        _data->_window->draw(*enemies2[i]);
    }
    for (int i = 0; i < animals.size(); i++)
    {
        _data->_window->draw(*animals[i]);
    }
    
   
    player->draw();
    _data->_window->display();
  
}


void map::createmap()
{
  
    for (int i = 0; i < length; i++)
    {

        addblock("grass");
    }


}

void map::addblock(std::string terrainName)
{
    block *newblock = new block(_data);

    newblock->init(terrainName, this->pos1, true, false);
    blocks.push_back(newblock); 
    if (addedroad == true)
    {
        newRoadIdx = blocks.size() - 1;
        newTrafficLightIdx = blocks.size() - 1;
    }
    else if (addedRiver == true)
    {
        newRiverIdx = blocks.size() - 1;
    }
    else if (addedgrass == true)
    {
        newGrassIdx = blocks.size() - 1;
    }

    this-> pos1.y -= 174.0-15-5;
    
}

map ::map(data *data)
{
    _data = data;
}
