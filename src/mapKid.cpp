#include "mapKid.h"

void mapKid::draw()
{
    if (isImmortal())
    {
        isEndgame = false;
        if (visiblePlayerDuration.getElapsedTime().asSeconds() >= 0.2f)
        {
            visiblePlayerDuration.restart();
            isPlayerVisible = !isPlayerVisible;
        }
    }
    else
    {
        isPlayerVisible = true;
    }
    drawTemplateNoPlayer();

    if (isPlayerVisible)
    {
        player->draw();
    }

    _data->_window->display();
}

bool mapKid::isImmortal() const
{
    return aliveDuration.getElapsedTime().asSeconds() <= 5.f;
}