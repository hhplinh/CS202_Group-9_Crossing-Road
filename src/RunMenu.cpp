#include <RunMenu.hpp>

void RunMenu::run(sf:: RenderWindow& window)
{
    while (CurrentScreen != nullptr)
    {
        std::unique_ptr<ScreenMenu> NextScreen = CurrentScreen->render(window);

        if (NextScreen != CurrentScreen)
        {
            CurrentScreen = std::move(NextScreen);
        }
    }
    return;
}

