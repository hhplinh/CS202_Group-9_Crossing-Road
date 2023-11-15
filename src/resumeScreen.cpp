#include "ResumeScreen.hpp"
#include "map.hpp"

ResumeScreen::ResumeScreen(data *data) : isPaused(true), countdown(3), _data(data)
{
}

ResumeScreen::~ResumeScreen()
{
}

void ResumeScreen::init()
{
    countdownText.setFont(_data->_assets->getFont(MAIN_FONT));
    countdownText.setCharacterSize(24);
    countdownText.setFillColor(sf::Color::White);
    countdownText.setPosition(_data->_window->getSize().x / 2.f, _data->_window->getSize().y / 2.f);
}

void ResumeScreen::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();
    }
}

void ResumeScreen::update()
{
    if (isPaused)
    {
        // Capture the current frame as a texture
        backgroundTexture.create(_data->_window->getSize().x, _data->_window->getSize().y);
        
        //NEED FIXING
        //GET WINDOW BEFORE PAUSE OF MAP
        // backgroundTexture.update(window);
        backgroundSprite.setTexture(backgroundTexture);

        if (clock.getElapsedTime().asSeconds() >= 1.f)
        {
            countdown--;
            clock.restart();
        }

        if (countdown <= 0)
        {
            isPaused = false;
            countdown = 3;
        }

        countdownText.setString(std::to_string(countdown));
    }
    else
    {
        // game -> pause -> remove pause -> resume -> remove resume -> game
        _data->_states->removeState();
    }
}

void ResumeScreen::draw()
{
    _data->_window->clear();
    if (isPaused)
    {
        _data->_window->draw(backgroundSprite);
        _data->_window->draw(countdownText);
    }

    _data->_window->display();
}