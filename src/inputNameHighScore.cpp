#include "inputNameHighScore.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

inputNameHighScore::inputNameHighScore(data *data) : _data(data)
{
}

inputNameHighScore::~inputNameHighScore()
{
}

void inputNameHighScore::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(BG_INPUT_NAME));
    backgroundSprite.setSize(sf::Vector2f(_data->_window->getSize().x, _data->_window->getSize().y));

    inputName.setFont(_data->_assets->getFont(MAIN_FONT));
    inputName.setCharacterSize(32);
    inputName.setFillColor(sf::Color::White);
    inputName.setPosition(10, 10);
}

void inputNameHighScore::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        isEventChanged = true;
        if (event.type == sf::Event::Closed)
            _data->_window->close();

        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Return:
            {
                inputName.setString(input);

                if (input.empty())
                {
                    break;
                }

                _data->_assets->setNameInputHighScore(input);
                _data->_assets->saveHighScore(input, _data->_assets->getScore());

                break;
            }

            case sf::Keyboard::Backspace:
            {
                if (!input.empty())
                {
                    input.pop_back();
                }
                break;
            }

            case sf::Event::TextEntered:
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {

                    input += static_cast<char>(event.text.unicode);
                }
                break;
            }
            default:
                break;
            }
        }
    }
}

void inputNameHighScore::update()
{
}

void inputNameHighScore::draw()
{
    if (isEventChanged)
    {
        _data->_window->clear();

        _data->_window->draw(backgroundSprite);

        _data->_window->draw(inputName);

        _data->_window->display();

        isEventChanged = false;
    }
}