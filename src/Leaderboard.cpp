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
    // countdownText.setFont(_data->_assets->getFont(MAIN_FONT));
    // countdownText.setCharacterSize(200);
    // countdownText.setFillColor(sf::Color::White);
    // countdownText.setOrigin(countdownText.getGlobalBounds().width / 2.f, countdownText.getGlobalBounds().height / 2.f);
    // countdownText.setPosition(_data->_window->getSize().x / 2.f, _data->_window->getSize().y / 2.f);
    // countdownText.setOutlineColor(_data->_assets->getThemeColor());
    // countdownText.setOutlineThickness(7.f);
}

void Leaderboard::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();
    }
}

void Leaderboard::update()
{
    // if (isPaused)
    // {

    //     if (clock.getElapsedTime().asSeconds() >= 1.f)
    //     {
    //         countdown--;
    //         clock.restart();
    //     }

    //     if (countdown <= 0)
    //     {
    //         isPaused = false;
    //         countdown = 3;
    //     }

    //     countdownText.setString(std::to_string(countdown));
    // }
    // else
    // {
    //     // game -> pause -> remove pause -> resume -> remove resume -> game
    //     _data->_states->removeState(false);
    // }
}

void Leaderboard::draw()
{
    _data->_window->clear();

    _data->_window->draw(backgroundSprite);
    //     _data->_window->draw(countdownText);
    // }

    _data->_window->display();
}