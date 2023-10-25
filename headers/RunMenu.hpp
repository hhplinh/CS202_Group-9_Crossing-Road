#ifndef RUNMENU_HPP
#define RUNMENU_HPP

#include <Library.hpp>
#include <ScreenMenu.hpp>

class RunMenu
{
private:
	std::unique_ptr<ScreenMenu> CurrentScreen;

public:
	RunMenu()
	{
		CurrentScreen = std::make_unique<HomeMenu>();
	};

	void run(sf:: RenderWindow& window);
};

#endif