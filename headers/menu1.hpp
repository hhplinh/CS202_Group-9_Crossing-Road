#pragma once
#include"state.h"
#include"system.h"
class menu1: public state
{
private:
    data* _data;
    sf::RectangleShape background;
public:
    menu1(data* data);
    ~menu1();
    void init();
	void processInput();
	void update();
	void draw();
};
