#pragma once
#include"state.h"
#include"system.h"



class block 
{
private:
    data* _data;
    bool isPassable;
	bool isExit;
  //  sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;  
    std::string terrainName;
   
public:
    block();
    std::string getTerrainName(){return terrainName;}
    block(data* _data){this->_data = _data;}
    void setpos( sf::Vector2f posblock);
    void init( std:: string terrainName  ,sf :: Vector2f pos , bool isPassable , bool isExit );
	void processInput();
	void update();
	void draw();
    //implement the get function to get pos
    sf::Vector2f getpos(){return sprite.getPosition();}
};