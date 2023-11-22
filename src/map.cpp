#include "map.hpp"
#include <memory>
#include <fstream>
#include "menuPause.hpp"
#include "endgameMenu.hpp"
#include "maincharacter.hpp"

void map::init()
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
void map::processInput()
{
    sf::Event event;

    while (_data->_window->pollEvent(event))
    {
        player->processInput(event);
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            savePressed = true;
        }
    }
}
void map::update()
{

    player->update();
    float pos = player->getPosition().y;

    float l = (pos / 1080.0 + 1);

    float j = -l;
    float k = int(l);
    float f = int(j);
    if (pos > 0)
    {
        currentIndex = 0;
    }
    else
    {
        currentIndex = int(1 + (pos) / -1080.0f) * 6;
    }
    float o = pos / -1080.0f - int((pos) / -1080.0f);

    // //std::cout << o << std::endl;
    if (((pos / 1080.0f) < 0.200000f && pos > 0 && blocks.size() < 20) || (o > 0.7f && o < 0.8f && pos < 0.0f && blocks.size() - currentIndex < 50))

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
                addedgrass = true;
                addblock("grass");
            }
            else if (z == 2)
            {
                addedRiver = true;
                addblock("river");
            }
        }
    }

    int u;

    river.clear();

    for (int i = currentIndex; i < blocks.size(); i++)
    {

        if (currentIndex < blocks.size())
        {
            if (blocks[i]->getTerrainName() == "river")
            {
                if (addedRiver == true && newRiverIdx == i)
                {
                    riverPos.push_back(blocks[i]->getpos());
                    addedRiver = false;
                    Cano *newCano = new Cano(_data);
                    enemies2.push_back(newCano);
                    enemies2[enemies2.size() - 1]->setPosCano(sf::Vector2f(riverPos.back().x, riverPos.back().y));
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
                    trafficlights[trafficlights.size() - 1]->setpos(roadpos.back().y);
                }
            }

            else if (blocks[i]->getTerrainName() == "grass")
            {
                if (addedgrass == true && newGrassIdx == i)
                {
                    grasspos.push_back(blocks[i]->getpos());
                    addedgrass = false;
                    u = rand() % 2;
                    Animal *a;
                    if (u == 1)
                    {
                        a = new cop(_data);
                    }
                    else
                        a = new gau(_data);
                    animals.push_back(a);
                    animals.back()->setposAnimal(sf::Vector2f(grasspos.back().x, grasspos.back().y));
                }
            }
        }
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        if (trafficlights[i]->carCanGo())
        {
            enemies[i]->run();
        }
        if (enemies[i]->getposcar().x > 1920 || enemies[i]->getposcar().x < 0)
        {
            enemies[i]->turnaround();
        }
    }

    for (int i = 0; i < enemies2.size(); i++)
    {
        enemies2[i]->floatOnRiver();

        // If the player intersects with the boat's global bounds
        if (player->getSprite().getGlobalBounds().intersects(enemies2[i]->getGlobalBounds()))
        {
            // If the player is moving up, attempt to get off the boat
            if (player->movingUp)
            {

                /*  player->setPosition(
                      player->getSprite().getPosition().x,
                      player->getSprite().getPosition().y - 100

                  );*/
                if (i + 1 < enemies2.size())
                {
                    if (isnextto(enemies2[i], enemies2[i + 1]))
                    {
                        floatwithboat(player, enemies2[i + 1]);
                    }
                }
                else
                {
                    // get off the boat
                    player->setPosition(player->getSprite().getPosition().x, player->getSprite().getPosition().y - 100);
                }
            }
            else
            {
                // If the player is not moving up, keep them on the boat
                floatwithboat(player, enemies2[i]);
            }
        }

        // Turn the boat around if it goes off-screen
        if (enemies2[i]->getPosCano().x > 1920 || enemies2[i]->getPosCano().x < 0)
        {
            enemies2[i]->turnAround();
        }
    }
    for (int i = 0; i < animals.size(); i++)
    { // std:: cout<< animals.size();
        animals[i]->AnimalRun();
        if (animals[i]->getposAnimal().x > 1920 || animals[i]->getposAnimal().x < 0)
        {
            animals[i]->AnimalTurn();
        }
    }

    if (savePressed)
    {
        saveGame();
        savePressed = false;
    }

    if (mescpressed == true)
    {
        backgroundTexture.create(_data->_window->getSize().x, _data->_window->getSize().y);
        backgroundTexture.update((const sf::RenderWindow &)(*(_data->_window)));
        _data->_assets->setBackgroundTexture(backgroundTexture);

        mescpressed = false;
        _data->_window->setView(_data->_window->getDefaultView());
        _data->_states->addState((new menuPause(_data)), false);
    }

    for (int i = 0; i < trafficlights.size(); i++)
    {
        trafficlights[i]->turn();
    }
    // std::cout << "current block : " << this->currentIndex << " : " << this->blocks.size() << std::endl;
}

void map::draw()
{
    _data->_window->clear();

    _data->_window->draw(background);

    for (int i = currentIndex; i < blocks.size(); i++)
    {
        // std::cout << "current block : " << this->currentIndex << " : " << this->blocks.size() << std::endl;
        if (currentIndex < blocks.size())
            // blocks[i]->setpos(pos);
            blocks[i]->draw();
    }
    // draw the car
    for (int i = 0; i < enemies.size(); i++)
    {
        _data->_window->draw(*enemies[i]);
    }
    for (int i = 0; i < trafficlights.size(); i++)
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
        animals[i]->draw();
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

    this->pos1.y -= 174.0 - 15 - 5;
}

map ::map(data *data)
{
    _data = data;
}

map::~map()
{
    std::cerr << "Deleting map\n";
    saveGame();
    // delete dynamically alocated memory
    // reset view

    _data->_window->setView(_data->_window->getDefaultView());
    // delete all the block and enemies

    for (int i = 0; i < blocks.size(); i++)
    {
        delete blocks[i];
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
    for (int i = 0; i < enemies2.size(); i++)
    {
        delete enemies2[i];
    }
    for (int i = 0; i < trafficlights.size(); i++)
    {
        delete trafficlights[i];
    }
    for (int i = 0; i < animals.size(); i++)
    {
        delete animals[i];
    }

    delete this->player;
}
// /*
// Biến toàn cục: current index //khối cuối màn hình

// -player: x,y

// -Block size
// -> top -> end of stack
// Mỗi stack block có position x, y -> vector 2f

// -Enemies
// Cụ thể: size + x,y mỗi phần tử
// Car: size
// Animal: size

// Load # chơi bth: load cái gần nhất
// Load: class loadMap:  kế thừa map
// player-> init đổi thành player->setPosition
// createMap-> loadMap

// ktra file có tồn tại ko, nv chết thì xóa file
// chỉnh isGameSaved
// */

// save game to a binary file, if that file exists, simply read info into it, if not create a new one
void map::saveGame()
{
    std::cerr << "Saving game\n";
    std::ofstream saveFile(_data->_assets->getSavedGamePath(), std::ios::binary);

    if (saveFile.is_open())
    {
        // save currentIndex
        saveFile.write((char *)&currentIndex, sizeof(int));

        // save pos1
        saveFile.write((char *)&pos1.x, sizeof(float));
        saveFile.write((char *)&pos1.y, sizeof(float));

        // save player position
        sf::Vector2f playerPos = player->getPosition();
        saveFile.write((char *)&playerPos, sizeof(sf::Vector2f));

        // save block size
        int blockSize = blocks.size();
        saveFile.write((char *)&blockSize, sizeof(int));

        // save block position and terrain name
        for (int i = 0; i < blockSize; i++)
        {
            std::string terrainName = blocks[i]->getTerrainName();
            saveFile.write((char *)&terrainName, sizeof(std::string));

            sf::Vector2f blockPos = blocks[i]->getpos();
            saveFile.write((char *)&blockPos, sizeof(sf::Vector2f));
        }

        // enemies = car
        //  save enemies size
        int enemiesSize = enemies.size();
        saveFile.write((char *)&enemiesSize, sizeof(int));

        // save enemies position
        // for (int i = 0; i < enemiesSize; i++)
        // {
        //     sf::Vector2f enemyPos = enemies[i]->getposcar();
        //     saveFile.write((char *)&enemyPos, sizeof(sf::Vector2f));
        // }

        // enemies2 = cano
        //  save enemies2 size
        int enemies2Size = enemies2.size();
        saveFile.write((char *)&enemies2Size, sizeof(int));

        // save enemies2 position
        // for (int i = 0; i < enemies2.size(); i++)
        // {
        //     sf::Vector2f enemy2Pos = enemies2[i]->getPosCano();
        //     saveFile.write((char *)&enemy2Pos, sizeof(sf::Vector2f));
        // }

        // save animals size
        int animalsSize = animals.size();
        saveFile.write((char *)&animalsSize, sizeof(int));
    }
    saveFile.close();
}

void map::loadGame()
{
    if (_data->_assets->isGameSaved() == false)
    {
        std::cerr << "No saved file available\n";
        return;
    }

    std::ifstream saveFile;
    saveFile.open(_data->_assets->getSavedGamePath(), std::ios::binary);
    if (saveFile.is_open())
    {
        // load currentIndex
        saveFile.read((char *)&currentIndex, sizeof(int));

        // load pos1
        saveFile.read((char *)&pos1.x, sizeof(float));
        saveFile.read((char *)&pos1.y, sizeof(float));

        // load player position
        sf::Vector2f playerPos;
        saveFile.read((char *)&playerPos, sizeof(sf::Vector2f));
        player->setPosition(playerPos.x, playerPos.y);

        std::cerr << "Player position: " << playerPos.x << " " << playerPos.y << std::endl;

        // load block size
        int blockSize;
        saveFile.read((char *)&blockSize, sizeof(int));
        std::cerr << "load block size\n";

        // load block position and terrain name
        for (int i = 0; i < blockSize; i++)
        {
            std::string terrainName;
            saveFile.read((char *)&terrainName, sizeof(std::string));

            sf::Vector2f blockPos;
            saveFile.read((char *)&blockPos, sizeof(sf::Vector2f));

            block *newblock = new block(_data);
            std::cerr << "Loading block\n";
            newblock->init(terrainName, blockPos, true, false);
            blocks.push_back(newblock);
        }

        // enemies = car
        //  load enemies size
        int enemiesSize;
        saveFile.read((char *)&enemiesSize, sizeof(int));

        // // load enemies position
        // for (int i = 0; i < enemiesSize; i++)
        // {
        //     sf::Vector2f enemyPos;
        //     saveFile.read((char *)&enemyPos, sizeof(sf::Vector2f));

        //     car *newcar = new car(_data);
        //     newcar->setposcar(enemyPos);
        //     enemies.push_back(newcar);
        // }
        std::cerr << "Loading enemies\n";

        // enemies2 = cano
        // load enemies2 size
        int enemies2Size;
        saveFile.read((char *)&enemies2Size, sizeof(int));

        // load enemies2 position
        // for (int i = 0; i < enemies2Size; i++)
        // {
        //     sf::Vector2f enemy2Pos;
        //     saveFile.read((char *)&enemy2Pos, sizeof(sf::Vector2f));
        //     Cano *newCano = new Cano(_data);
        //     newCano->setPosCano(enemy2Pos);
        //     enemies2.push_back(newCano);
        // }
        std::cerr << "Loading enemies2\n";

        // load animals size
        int animalsSize;
        saveFile.read((char *)&animalsSize, sizeof(int));
        std::cerr << "Loading animals\n";
    }
    std::cerr << "Loading saved file\n";
    saveFile.close();
}