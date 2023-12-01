#include "instructScr.hpp"
#include "mainMenu.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

instructScreen::instructScreen(data *data) : _data(data)
{
}

instructScreen::~instructScreen()
{
}
std::string instructScreen::loadTextFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string content;
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            content += line + "\n";
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return content;
}

void instructScreen::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(BACKGROUND2));
    backgroundSprite.setSize(sf::Vector2f(1920, 1080));
    backgroundSprite.setFillColor(sf::Color::White);

    std::string insText = loadTextFromFile(INSTRUCT_PATH);
    instructText.setFont(_data->_assets->getFont(MAIN_FONT));
    instructText.setCharacterSize(75);
    instructText.setFillColor(sf::Color::White);
    instructText.setOrigin(instructText.getGlobalBounds().width / 2.f, instructText.getGlobalBounds().height / 2.f);
    instructText.setString(insText);
    instructText.setPosition(500.f, 350.f);
    instructText.setOutlineColor(_data->_assets->getThemeColor());
    instructText.setOutlineThickness(7.f);

    board.setSize(sf::Vector2f(1150, 400));
    board.setPosition(sf::Vector2f(475, 330));
    board.setFillColor(sf::Color(255, 255, 255, 150));
}

void instructScreen::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            _data->_states->addState(new mainMenu(_data), true);
        }
    }
}

void instructScreen::update()
{
}

void instructScreen::draw()
{
    _data->_window->clear();
    _data->_window->draw(backgroundSprite);
    _data->_window->draw(instructText);
    _data->_window->draw(board);
    //     _data->_window->draw(countdownText);
    // }
    _data->_window->display();
}