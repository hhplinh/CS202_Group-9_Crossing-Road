#include "system.h"
#include "mainMenu.hpp"
#include "MainMenu0Load.hpp"
#include "inputNameHighScore.hpp"
#include "endgameMenu.hpp"
#include"map.hpp"
#include <iostream>
System::System() : _data(new data)
{   _data->isEndgame = false;

	_data->_window->create(sf::VideoMode(1920, 1080), "Crossing Road", sf::Style::Close);

	_data->_window->setMouseCursorVisible(false);
	
	if (_data->_assets->isGameSaved())
	{
		_data->_states->addState(new mainMenu(_data));
	}
	else
	{
		_data->_states->addState(new mainMenu0Load(_data));
	}
	
	_data->_assets->createHighScoreFile();

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
			 if (_data->isEndgame)
        {  
	_data->_states->getCurrentState()->draw();
            // Check if 2 seconds have passed
            if (_data->endgameStartTime.getElapsedTime().asSeconds() >= 2)
            {
                // Endgame delay is over
                if (_data->_assets->isInTopScore(_data->score))
                {_data->_window->setView(_data->_window->getDefaultView());
                    _data->_states->addState(new inputNameHighScore(_data), true);
                }
                else
                {_data->_window->setView(_data->_window->getDefaultView());
                    _data->_states->addState(new endgameMenu(_data), true);
                }

                // Reset the endgame state
                _data->isEndgame = false;
            }
        }
		else{
			_data->_states->processStateChange();
			_data->_states->getCurrentState()->processInput();
			_data->_states->getCurrentState()->update();
			_data->_states->getCurrentState()->draw();
		}
		}
	 
	}
}
