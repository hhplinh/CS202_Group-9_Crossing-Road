#pragma once
#include"state.h"
#include"system.h"



class block 
{
private:
    data* _data;
    bool isPassable;
	bool isExit;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;  
    std::string terrainName;
   
public:
    block();
    
    void init( std:: string terrainName  ,sf :: Vector2f pos , bool isPassable , bool isExit );
	void processInput();
	void update();
	void draw();
};