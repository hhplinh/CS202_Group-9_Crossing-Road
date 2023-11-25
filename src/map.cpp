#include <memory>
#include <fstream>

#include "map.hpp"
#include "menuPause.hpp"
#include "endgameMenu.hpp"
#include "maincharacter.hpp"
#include "resumeScreen.hpp"

void map::init()
{ // do not init if resume from pause menu
  // check the state size
    // using state machine size
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);
    this->cooldownActive = false;
    this->cooldownDuration = 1.0f;
    player = new maincharacter(_data);
    player->init();
    this->blocks.clear();
    this->point = 0;
    this->river.clear();
    this->length = 10;

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
    if (pos > 0)
        this->point = (1080 - pos);
    else
        this->point = 1080 + abs(pos);
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
        if (player->getSprite().getGlobalBounds().intersects(enemies2[i]->getGlobalBounds()) && !player->movingUp)
        {
            // Float with the boat
            floatwithboat(player, enemies2[i]);

            // Check if player is next to the next boat (if it exists)
            if (i + 1 < enemies2.size() && isnextto(enemies2[i], enemies2[i + 1]))
            {
                // Float with the nearby boat and set a cooldown period
                if (!cooldownActive)
                {
                    floatwithboat(player, enemies2[i + 1]);
                    cooldownClock.restart();
                    cooldownActive = true;
                }
            }
        }
        if (enemies2[i]->getPosCano().x > 1920 || enemies2[i]->getPosCano().x < 0)
        {
            enemies2[i]->turnAround();
        }
    }

    // Set playerIsOnBoat to false by default
    playerIsOnBoat = false;

    // Check if the player is on any boat
    for (int i = 0; i < enemies2.size(); i++)
    {
        if (player->getSprite().getGlobalBounds().intersects(enemies2[i]->getGlobalBounds()))
        {
            playerIsOnBoat = true;
            break;
        }
    }

    for (int i = 0; i < riverPos.size(); i++)
    { // check if pos of player is on river (>riverpos[i].y) (<riverpos[i].y+174)
        if (player->getSprite().getPosition().y > riverPos[i].y && player->getSprite().getPosition().y < riverPos[i].y + 174 - 50)
        {
            // check if player is on boat
            if (playerIsOnBoat == false)
            { // reset view
                // if not on boat, game over
                _data->_window->setView(_data->_window->getDefaultView());
                this->endgame();
            }
        }
    }
    for (int i = 0; i < animals.size(); i++)
    { // std:: cout<< animals.size();
        animals[i]->AnimalRun();
        collisonWithAnimal(player, animals[i]);
        if (animals[i]->getposAnimal().x > 1920 || animals[i]->getposAnimal().x < 0)
        {
            animals[i]->AnimalTurn();
        }
    }

    if (savePressed)
    {
        saveGame();

        gameSavedTextNeeded = true;
        savedTextClock.restart();

        gameSavedText.setFont(_data->_assets->getFont(MAIN_FONT));
        gameSavedText.setString("Game saved!");
        gameSavedText.setCharacterSize(110);
        gameSavedText.setOrigin(gameSavedText.getLocalBounds().width / 2.f, gameSavedText.getLocalBounds().height / 2.f);

        gameSavedText.setFillColor(sf::Color::White);
        gameSavedText.setOutlineColor(_data->_assets->getThemeColor());
        gameSavedText.setOutlineThickness(7.f);

        // position below player
        gameSavedText.setPosition(player->getPosition().x, player->getPosition().y + 400.f);

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

    score.setFont(_data->_assets->getFont(MAIN_FONT));
    score.setString("Score: " + std::to_string(this->point));
    score.setCharacterSize(70);
    score.setOrigin(score.getLocalBounds().width / 2.f, score.getLocalBounds().height / 2.f);
    score.setPosition(_data->_window->getSize().x / 2.f, player->getPosition().y - 400.f);

    score.setFillColor(sf::Color::White);
    score.setOutlineColor(_data->_assets->getThemeColor());
    score.setOutlineThickness(7.f);
}

void map::draw()
{
    drawTemplate();
    _data->_window->display();
}

void map::drawTemplate()
{
    _data->_window->clear();

    _data->_window->draw(background);

    for (int i = currentIndex; i < blocks.size(); i++)
    {
        // std::cout << "current block : " << this->currentIndex << " : " << this->blocks.size() << std::endl;
        if (currentIndex < blocks.size())
        // blocks[i]->setpos(pos);
        {
            blocks[i]->draw();
        }
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

    // show text for 3 seconds
    if (gameSavedTextNeeded && savedTextClock.getElapsedTime().asSeconds() >= 3.f)
    {
        gameSavedTextNeeded = false;
    }
    else if (gameSavedTextNeeded)
    {
        _data->_window->draw(gameSavedText);
    }

    // draw score
    _data->_window->draw(score);
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

void map::saveGame()
{
    bool isEasyLevel = isEasy();

    _data->_assets->setEasyLevelSavedGame(isEasyLevel);
    std::ofstream saveFile(_data->_assets->getSavedGamePath(), std::ios::binary);

    if (saveFile.is_open())
    {
        // save bool isEasyLevelSaved
        saveFile.write((char *)&isEasyLevel, sizeof(bool));

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

        // save block terrain name and position
        for (int i = 0; i < blockSize; i++)
        {
            std::string terrainName = blocks[i]->getTerrainName();
            int len = terrainName.size();
            saveFile.write((char *)&len, sizeof(int));
            saveFile.write(terrainName.c_str(), len);

            sf::Vector2f blockPos = blocks[i]->getpos();
            saveFile.write((char *)&blockPos, sizeof(sf::Vector2f));
        }

        // enemies = car
        //  save enemies size
        int enemiesSize = enemies.size();
        saveFile.write((char *)&enemiesSize, sizeof(int));

        // save enemies position
        for (int i = 0; i < enemiesSize; i++)
        {
            sf::Vector2f enemyPos = enemies[i]->getposcar();
            saveFile.write((char *)&enemyPos, sizeof(sf::Vector2f));
        }

        // enemies2 = cano
        //  save enemies2 size
        int enemies2Size = enemies2.size();
        saveFile.write((char *)&enemies2Size, sizeof(int));

        // save enemies2 position
        for (int i = 0; i < enemies2Size; i++)
        {
            sf::Vector2f enemy2Pos = enemies2[i]->getPosCano();
            saveFile.write((char *)&enemy2Pos, sizeof(sf::Vector2f));
        }

        // save animals size
        int animalsSize = animals.size();
        saveFile.write((char *)&animalsSize, sizeof(int));

        // save animals position
        for (int i = 0; i < animalsSize; i++)
        {
            sf::Vector2f animalPos = animals[i]->getposAnimal();
            saveFile.write((char *)&animalPos, sizeof(sf::Vector2f));
        }

        // save traffic lights, save all parameters of traffic lights
        int trafficLightsSize = trafficlights.size();
        saveFile.write((char *)&trafficLightsSize, sizeof(int));

        // save traffic lights parameters
        for (int i = 0; i < trafficLightsSize; i++)
        {
            int col = trafficlights[i]->getcol();
            int row = trafficlights[i]->getrow();
            sf::Vector2u size = trafficlights[i]->getsize();
            bool isGreen = trafficlights[i]->getIsGreen();
            sf::Vector2f pos = trafficlights[i]->getpos();

            saveFile.write((char *)&col, sizeof(int));
            saveFile.write((char *)&row, sizeof(int));
            saveFile.write((char *)&size, sizeof(sf::Vector2u));
            saveFile.write((char *)&isGreen, sizeof(bool));
            saveFile.write((char *)&pos, sizeof(sf::Vector2f));
        }
    }
    else
    {
        std::cerr << "Unable to open file\n";
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
        // load bool isEasyLevelSaved
        bool isEasyLevelSaved;
        saveFile.read((char *)&isEasyLevelSaved, sizeof(bool));

        // load currentIndex
        saveFile.read((char *)&currentIndex, sizeof(int));

        // load pos1
        saveFile.read((char *)&pos1.x, sizeof(float));
        saveFile.read((char *)&pos1.y, sizeof(float));

        // save to retrieve later
        sf::Vector2f temp = pos1;

        // load player position
        sf::Vector2f playerPos;
        saveFile.read((char *)&playerPos, sizeof(sf::Vector2f));
        player->setPosition(playerPos.x, playerPos.y);

        // load block size
        int blockSize;
        saveFile.read((char *)&blockSize, sizeof(int));

        blocks.clear();

        // load block terrain name
        for (int i = 0; i < blockSize; i++)
        {
            int len;
            saveFile.read((char *)&len, sizeof(int));

            char *buffer = new char[len + 1];
            saveFile.read(buffer, len);
            std::string terrainName(buffer, len);
            delete[] buffer;

            sf::Vector2f blockPos;
            saveFile.read((char *)&blockPos, sizeof(sf::Vector2f));

            pos1 = blockPos;
            addblock(terrainName);
        }

        pos1 = temp;

        int enemiesSize;
        saveFile.read((char *)&enemiesSize, sizeof(int));
        enemies.clear();

        for (int i = 0; i < enemiesSize; i++)
        {
            sf::Vector2f enemyPos;
            saveFile.read((char *)&enemyPos, sizeof(sf::Vector2f));

            car *newcar = new car(_data);
            newcar->setposcar(sf::Vector2f(enemyPos.x, enemyPos.y));
            enemies.push_back(newcar);
        }

        int enemies2Size;
        saveFile.read((char *)&enemies2Size, sizeof(int));
        enemies2.clear();

        for (int i = 0; i < enemies2Size; i++)
        {
            sf::Vector2f enemy2Pos;
            saveFile.read((char *)&enemy2Pos, sizeof(sf::Vector2f));

            Cano *newCano = new Cano(_data);
            newCano->setPosCano(sf::Vector2f(enemy2Pos.x, enemy2Pos.y));
            enemies2.push_back(newCano);
        }

        int animalsSize;
        saveFile.read((char *)&animalsSize, sizeof(int));
        animals.clear();

        for (int i = 0; i < animalsSize; i++)
        {
            sf::Vector2f animalPos;
            saveFile.read((char *)&animalPos, sizeof(sf::Vector2f));

            Animal *a;
            if (isEasyLevelSaved)
            {
                a = new gau(_data);
            }
            else
            {
                a = new cop(_data);
            }
            a->setposAnimal(sf::Vector2f(animalPos.x, animalPos.y));
            animals.push_back(a);
        }

        int trafficLightsSize;
        saveFile.read((char *)&trafficLightsSize, sizeof(int));
        trafficlights.clear();

        for (int i = 0; i < trafficLightsSize; i++)
        {
            int col;
            int row;
            sf::Vector2u size;
            bool isGreen;
            sf::Vector2f pos;

            saveFile.read((char *)&col, sizeof(int));
            saveFile.read((char *)&row, sizeof(int));
            saveFile.read((char *)&size, sizeof(sf::Vector2u));
            saveFile.read((char *)&isGreen, sizeof(bool));
            saveFile.read((char *)&pos, sizeof(sf::Vector2f));

            trafficlight *newtrafficlight = new trafficlight(_data);
            newtrafficlight->setcol(col);
            newtrafficlight->setrow(row);
            newtrafficlight->setsize(size);
            newtrafficlight->setIsGreen(isGreen);
            newtrafficlight->setposSave(pos);
            trafficlights.push_back(newtrafficlight);
        }
    }
    else
    {
        std::cerr << "Unable to open file\n";
    }
    saveFile.close();
}

void map::loadCountdownScreen()
{
    // Save window screen to texture
    backgroundTexture.create(_data->_window->getSize().x, _data->_window->getSize().y);
    backgroundTexture.update((const sf::RenderWindow &)(*(_data->_window)));
    _data->_assets->setBackgroundTexture(backgroundTexture);
    _data->_window->setView(_data->_window->getDefaultView());

    _data->_states->addState(new ResumeScreen(_data), false);
}