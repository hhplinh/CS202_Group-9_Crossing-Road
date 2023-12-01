#include "Leaderboard.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Leaderboard::Leaderboard(data *data) : _data(data)
{
}

Leaderboard::~Leaderboard()
{
}

void Leaderboard::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(LEADERBOARD));
    backgroundSprite.setSize(sf::Vector2f(1920, 1080));
}

void Leaderboard::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                _data->_states->removeStateUntilOne();
                break;
            default:
                break;
            }
        }
    }
}

void Leaderboard::update()
{
}

void Leaderboard::draw()
{
    _data->_window->clear();

    _data->_window->draw(backgroundSprite);
    //     _data->_window->draw(countdownText);
    // }

    _data->_window->display();
}