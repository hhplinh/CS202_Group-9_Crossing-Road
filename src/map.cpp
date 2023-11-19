#include "map.hpp"

#include "menuPause.hpp"
#include "endgameMenu.hpp"
#include "maincharacter.hpp"
void map::init()
{ // do not init if resume from pause menu
  // check the state size
    // using state machine size

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
    // while (_data->_window->pollEvent(event))
    //{
    // switch (event.type)
    //{
    // case sf::Event::Closed:
    //	_data->_window->close();
    //	break;
    // }
    //}
   // player->processInput();
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

    float i = (pos / 1080.0 + 1);

    float j = -i;
    int k = int(i);
    int f = int(j);
    if (k > this->currentIndex)
    {
        this->currentIndex = k;
    }

    if (((i - k) < 0.2 && pos > 0) || (j - f > 0.7 && (j - f) < 0.8 && pos < 0))
    {
        int z;
        for (int i = 0; i < 1; i++)
        {
            z = rand() % 3;

            if (z == 0)
            {
                addedroad = true;
                addblock("road");
            }
            else if (z == 1)
            {
                addblock("grass");
            }
            else if (z == 2)
            {
                addedRiver = true;
                addblock("river");
            }
        }
    }

    sf::Vector2f pos1(0.0f, 906.0f);

    river.clear();

    for (int i = currentIndex; i < blocks.size(); i++)
    {
        blocks[i]->setpos(pos1);

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
                enemies.push_back(newcar);
                enemies[enemies.size() - 1]->setposcar(sf::Vector2f(roadpos.back().x, roadpos.back().y + 50));
            }
        }
        pos1.y -= 174.0 - 15 - 5;
    }
    sf::Vector2f screenSize(1920, 1080); // Adjust this based on your screen size

    for (const auto &riverBlockPos : river)
    {
        float riverBlockHeight = /* height of your river blocks */ 174;

        // Check if player is within the vertical span of the river block
        if ((player->getPosition().y + 143) > riverBlockPos.y &&
            (player->getPosition().y + 143) < (riverBlockPos.y + riverBlockHeight))
        {
            // Collision detected, player is in the river
            // player->setPosition(0,prePos);
            // return;  // Exit the update function
        }
    }
    // run the car
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->run();
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
      if (mescpressed == true)
      {  mescpressed = false;
          _data->_states->addState((new menuPause(_data)), false);
            _data->_window->setView(_data->_window->getDefaultView());
      }
        // animal run
   
 
       std:: cout<< player->getStamina()<<std::endl;
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
    // draw the cano
    for (int i = 0; i < enemies2.size(); i++)
    {
        _data->_window->draw(*enemies2[i]);
    }
    // set player position to the bottom of the screen
    player->draw();
    _data->_window->display();
    // detect player in river
}

// void map::draw()
// {
//     _data->_window->clear();

//     // _data->_window->draw(background);

//     // for (int i = currentIndex; i < blocks.size(); i++)
//     // {
//     //     // blocks[i]->setpos(pos);
//     //     blocks[i]->draw();
//     // }
//     // // draw the car
//     // for (int i = 0; i < enemies.size(); i++)
//     // {
//     //     _data->_window->draw(*enemies[i]);
//     // }
//     // // draw the cano
//     // for (int i = 0; i < enemies2.size(); i++)
//     // {
//     //     _data->_window->draw(*enemies2[i]);
//     // }
//     // // set player position to the bottom of the screen
//     // player->draw();

//     _data->_window->draw(backgroundSprite);
//     _data->_window->display();
//     // detect player in river
// }

void map::createmap()
{
    int z;
    for (int i = 0; i < length; i++)
    {

        addblock("grass");
    }

    //   blocks[0]->draw();
}

void map::addblock(std::string terrainName)
{
    block *newblock = new block(_data);
    sf::Vector2f poss(0, 0);
    newblock->init(terrainName, poss, true, false);
    blocks.push_back(newblock); 
    if (addedroad == true)
    {
        newRoadIdx = blocks.size() - 1;
    }
    else if (addedRiver == true)
    {
        newRiverIdx = blocks.size() - 1;
    }
    else if (addedgrass == true)
    {
        newGrassIdx = blocks.size() - 1;
    }
    // pos1.y -= 174.0-15-5;
    
}

map ::map(data *data)
{
    _data = data;
}
