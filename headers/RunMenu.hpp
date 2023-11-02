#ifndef RUNMENU_HPP
#define RUNMENU_HPP

#include <SFML/Graphics.hpp>
#include <ScreenMenu.hpp>
#include <memory>

class RunMenu
{
private:
	std::unique_ptr<ScreenMenu> CurrentScreen;

public:
	RunMenu()
	{
		CurrentScreen = std::make_unique<HomeMenu>();
	};

	void run();
};

#endif