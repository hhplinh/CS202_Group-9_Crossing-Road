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
    float padding = 50.f;
    backgroundSprite.setTexture(&_data->_assets->getTexture(BACKGROUND2));
    backgroundSprite.setSize(sf::Vector2f(1920, 1080));
    backgroundSprite.setFillColor(sf::Color::White);

    std::string insText = loadTextFromFile(INSTRUCT_PATH);
    instructText.setFont(_data->_assets->getFont(MAIN_FONT));
    instructText.setCharacterSize(45);
    instructText.setFillColor(sf::Color::White);
    instructText.setString(insText);
    instructText.setOutlineColor(_data->_assets->getThemeColor());
    instructText.setOutlineThickness(5.f);
    instructText.setOrigin(instructText.getGlobalBounds().width / 2.f, instructText.getGlobalBounds().height / 2.f);
    instructText.setPosition(_data->_window->getSize().x / 2.f, _data->_window->getSize().y / 2.f + 100);

    board.setSize(sf::Vector2f(instructText.getLocalBounds().width + padding * 2, instructText.getLocalBounds().height + padding * 2));
    board.setFillColor(sf::Color(253, 233, 190, 150));
    board.setOrigin(board.getLocalBounds().width / 2.f, board.getLocalBounds().height / 2.f);
    // board.setPosition(_data->_window->getSize().x / 2.f, _data->_window->getSize().y / 2.f + 90);
    board.setPosition(instructText.getPosition());
}

void instructScreen::processInput()
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
            case sf::Keyboard::Enter:
            {
                _data->_states->removeStateUntilOne();
                break;
            }
            case sf::Keyboard::Escape:
            {
                _data->_states->removeStateUntilOne();
                break;
            }

            default:
            {
                break;
            }
            }
        }
    }
}

void instructScreen::update()
{
}

void instructScreen::draw()
{
    if (isEventChanged)
    {
        isEventChanged = false;
        _data->_window->clear();
        _data->_window->draw(backgroundSprite);
        _data->_window->draw(board);
        _data->_window->draw(instructText);
        _data->_window->display();
    }
}