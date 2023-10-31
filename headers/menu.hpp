#pragma once
#include"state.h"
#include"system.h"
class menu: public state
{
private:
    data* _data;
    sf::Sprite backgroundTexture;
    sf::RectangleShape background;
public:
    menu(data* data);
    ~menu();
    void init();
	void processInput();
	void update();
	void draw();


};
