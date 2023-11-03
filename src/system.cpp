#include"system.h"
#include "mainMenu.hpp"
#include<iostream>
System::System() : _data(new data)
{
	_data->_window->create(sf::VideoMode(1920, 1080), "Crossing Road", sf::Style::Close);
	_data->_states->addState(new mainMenu(_data));
	_data->_window->setMouseCursorVisible(false);

	run();
}
System::~System()
{
}
void System::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;

	while (_data->_window->isOpen())
		{
			timeSinceLastFrame += clock.restart();
			while (timeSinceLastFrame > TIME_PER_FRAME)
			{
				timeSinceLastFrame -= TIME_PER_FRAME;
				_data->_states->processStateChange();
				_data->_states->getCurrentState()->processInput();
				_data->_states->getCurrentState()->update();
				_data->_states->getCurrentState()->draw();
			}
		}
}

