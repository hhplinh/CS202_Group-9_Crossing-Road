#pragma once
#include "state.h"
#include "system.h"
#include "maincharacter.hpp"

#include "enemy.hpp"
#include <vector>

#include "car.hpp"
#include "cano.hpp"
#include "menu.hpp"

#include "mapfeature.hpp"
#include "trafficlight.hpp"
#include "Animal.hpp"
#include"endgameMenu.hpp"
class menuPause;
class endgameMenu;
class map : public state
{
protected:
    sf::Vector2f pos1;
    bool mescpressed = false;
    bool savePressed = false;
    std ::vector<block *> blocks;
    data *_data;
    std ::vector<car *> enemies;
    std::vector<Cano *> enemies2;
    std::vector<trafficlight *> trafficlights;
    maincharacter *player;
    bool playerIsOnBoat = false;

    int currentIndex;
    std ::vector<Animal *> animals;
    sf::Texture backgroundTexture;

    virtual void loadGame();
    virtual void saveGame();

    virtual bool isEasy()
    {
        return 0;
    }
  int point;
public:
    Cano *currentBoat = NULL;
    Cano *nextBoat = NULL;
    bool isnextto(Cano *currentBoat, Cano *nextBoat)
    {
        if (currentBoat->getSprite().getPosition().x + currentBoat->getSprite().getGlobalBounds().width == nextBoat->getSprite().getPosition().x)
        {
            return true;
        }
        return false;
    }
    bool floatwithboat(maincharacter *player, Cano *cano1)
    { // set player pos to the middle of the boat
        player->setPosition(cano1->getSprite().getPosition().x + cano1->getSprite().getGlobalBounds().width / 2 - player->size.x / 2, cano1->getSprite().getPosition().y + cano1->getSprite().getGlobalBounds().height / 2 - player->size.y / 2);
        this->playerIsOnBoat = true;
        return 1;
    }

    // get the current window screen
    sf::RenderWindow *getWindow()
    {
        return _data->_window;
    }
    std::vector<sf::Vector2f> roadpos;
    int length;
    std::vector<sf::Vector2f> river;
    std::vector<sf::Vector2f> riverPos;
    std::vector<sf ::Vector2f> grasspos;
    map(data *data);
    map();
    // virtual ~map();
    ~map();

    void addcar();
    bool addedroad = false;
    bool addedRiver = false;
    bool addedgrass = false;
    int newGrassIdx = -1;
    int newRoadIdx = -1;
    int newRiverIdx = -1;
    int newTrafficLightIdx = -1;
    virtual void init();
    void processInput();
    void update();
    virtual void draw();
    void createmap();
    void addblock(std::string terrainName);
    sf::RectangleShape background;
    void moveToGameOverMenu()
    {
        _data->_states->addState(new endgameMenu(_data), true);
    }
    void collisonWithCar( maincharacter *player, car * car1)
    {
        if (player->getSprite().getGlobalBounds().intersects(car1->getSprite().getGlobalBounds()))
        {
            moveToGameOverMenu();
        }

    }
  //collison with animal
    void collisonWithAnimal( maincharacter *player, Animal * animal1)
    {
        if (player->getSprite().getGlobalBounds().intersects(animal1->getSprite().getGlobalBounds()))
        {
            moveToGameOverMenu();
        }
    
    }
   
   

};