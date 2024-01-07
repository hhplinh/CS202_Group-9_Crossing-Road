#include "system.h"
#include "mainMenu.hpp"
#include "MainMenu0Load.hpp"
#include "musicManager.h"
#include <SFML/Audio.hpp>

#include <iostream>
System::System() : _data(new data)
{
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
	delete _data;
	_data = nullptr;
}
void System::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;

	// sf::Music music;

	// if (!music.openFromFile("BackgroundMusic.ogg"))
	// {
	// 	std::cerr << "ERROR LOADING MUSIC" << std::endl;
	// }
	// else
	// {
	// 	music.setVolume(50);
	// 	music.setLoop(true);
	// 	music.play();
	// }

	MusicManager &musicManager = MusicManager::getInstance();
	musicManager.loadMusic("BackgroundMusic.ogg");
	musicManager.configureMusic(50, true);
	musicManager.playMusic();

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
