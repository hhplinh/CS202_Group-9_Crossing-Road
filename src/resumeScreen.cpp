#include "ResumeScreen.hpp"
#include "map.hpp"

ResumeScreen::ResumeScreen(data *data) : window(sf::VideoMode(800, 600), "Resume Menu"), isPaused(true), countdown(3), _data(data)
{

    countdownText.setFont(data->_assets->getFont(MAIN_FONT));
    countdownText.setCharacterSize(24);
    countdownText.setFillColor(sf::Color::Red);
    countdownText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

ResumeScreen::~ResumeScreen()
{

}

void ResumeScreen::processInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void ResumeScreen::update()
{
    if (isPaused)
    {
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

        countdownText.setString("Resuming in: " + std::to_string(countdown));
    }
    else
    {
        _data->_states->addState(new map(_data));
    }
}

void ResumeScreen::draw()
{
    window.clear();
    if (isPaused)
    {
        window.draw(backgroundSprite);
        window.draw(countdownText);
    }

    window.display();
}