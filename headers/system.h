#pragma once
#include"assetManager.h"
#include"stateMachine.h"
class data
{
	public:
	assetManager* _assets;
	stateMachine* _states;
	sf::RenderWindow* _window;
	data()
	{
		_assets = new assetManager;
		_states = new stateMachine;
		_window = new sf::RenderWindow;

	}
	~data()
	{
		delete _assets;
		_assets = nullptr;

		delete _states;
		_states = nullptr;

		delete _window;
		_window = nullptr;
	}
};
class System
{
private:
	data* _data;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
public:
	System();
	~System();
	void run();
};



