#include "inputNameHighScore.hpp"
#include "Leaderboard.hpp"
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
    inputName.setCharacterSize(50);
    inputName.setFillColor(sf::Color::White);
    inputName.setString("Name");
    inputName.setOrigin(inputName.getGlobalBounds().width / 2, inputName.getGlobalBounds().height / 2);
    inputName.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);

    score.setFont(_data->_assets->getFont(MAIN_FONT));
    score.setCharacterSize(50);
    score.setString(std::to_string(_data->_assets->getScore()));
    score.setFillColor(sf::Color::White);
    score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 2);
    score.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2);
}

void inputNameHighScore::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        isEventChanged = true;
        if (event.type == sf::Event::Closed)
            _data->_window->close();

        else if (event.type == sf::Event::TextEntered)
        {
            if (input.size() <= MAX_NAME_LENGTH && event.text.unicode < 128)
            {
                input += static_cast<char>(event.text.unicode);
                inputName.setString(input);
            }
            break;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Enter:

                inputName.setString(input);

                if (!input.empty())
                {
                    _data->_assets->setNameInputHighScore(input);
                    _data->_assets->saveHighScore(input, _data->_assets->getScore());
                    _data->_states->addState(new Leaderboard(_data), true);
                }

                break;

            case sf::Keyboard::Backspace:

                if (!input.empty())
                {
                    input.pop_back();
                }
                break;

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
        isEventChanged = false;
        _data->_window->clear();

        _data->_window->draw(backgroundSprite);
        
        inputName.setOrigin(inputName.getGlobalBounds().width / 2, inputName.getGlobalBounds().height / 2);
        inputName.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 100);
        _data->_window->draw(inputName);
        _data->_window->draw(score);

        _data->_window->display();
    }
}