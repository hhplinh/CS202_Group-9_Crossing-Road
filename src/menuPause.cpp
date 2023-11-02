#include "menuPause.hpp"

#include "maincharacter.hpp"
#include "map.hpp"
#include "menu.hpp"

menuPause::menuPause(data *data)
    : _data(data), m_resumeSelected(false), m_resumePressed(false), m_returnMainMenuSelected(false), m_returnMainMenuPressed(false)
{
}
menuPause::~menuPause() {}
void menuPause::init()
{
    _data->_assets->addTexture(BACKGROUND, "resources//background.png");
    _data->_assets->addTexture(ROAD, "resources//road.png");
    _data->_assets->addTexture(RIVER, "resources//river.png");
    background.setTexture(&_data->_assets->getTexture(BACKGROUND));

    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);

    _data->_assets->addFont(MAIN_FONT, "resources//arial.ttf");

    // Title
    m_gametitle.setFont(_data->_assets->getFont(MAIN_FONT));
    m_gametitle.setString("CrossyRoad");
    m_gametitle.setOrigin(m_gametitle.getLocalBounds().width / 2,
                          m_gametitle.getLocalBounds().height / 2);
    m_gametitle.setPosition(_data->_window->getSize().x / 2,
                            _data->_window->getSize().y / 2 - 150.f);

    // Resume Button
    m_resume.setFont(_data->_assets->getFont(MAIN_FONT));
    m_resume.setString("Resume");
    m_resume.setOrigin(m_resume.getLocalBounds().width / 2,
                       m_resume.getLocalBounds().height / 2);
    m_resume.setPosition(_data->_window->getSize().x / 2,
                         _data->_window->getSize().y / 2 - 25.f);
    m_resume.setCharacterSize(50);

    // Return main menu Button
    m_returnMainMenu.setFont(_data->_assets->getFont(MAIN_FONT));
    m_returnMainMenu.setString("Return to main menu");
    m_returnMainMenu.setOrigin(m_returnMainMenu.getLocalBounds().width / 2,
                               m_returnMainMenu.getLocalBounds().height / 2);
    m_returnMainMenu.setPosition(_data->_window->getSize().x / 2,
                                 _data->_window->getSize().y / 2 + 25.f);
    m_returnMainMenu.setCharacterSize(50);

    
}
void menuPause::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _data->_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!m_resumeSelected && m_returnMainMenuSelected)
                {
                    m_resumeSelected = true;
                    m_returnMainMenuSelected = false;
                }
                else if (m_resumeSelected && !m_returnMainMenuSelected)
                {
                    m_returnMainMenuSelected = false;
                    m_resumeSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_resumeSelected && m_returnMainMenuSelected)
                {
                    m_resumeSelected = true;
                    m_returnMainMenuSelected = false;
                }
                else if (m_resumeSelected && !m_returnMainMenuSelected)
                {
                    m_returnMainMenuSelected = true;
                    m_resumeSelected = false;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                m_resumePressed = false;
                m_returnMainMenuPressed = false;


                if (m_resumeSelected)
                {
                    m_resumePressed = true;
                }
                else if (m_returnMainMenuSelected)
                {
                    m_returnMainMenuPressed = true;
                }
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

void menuPause::update()
{
    if (m_resumeSelected)
    {
        m_resume.setFillColor(sf::Color::Black);
        m_returnMainMenu.setFillColor(sf::Color::White);
    }
    if (m_returnMainMenuSelected)
    {
        m_returnMainMenu.setFillColor(sf::Color::Black);
        m_resume.setFillColor(sf::Color::White);
    }

    else if (m_resumePressed)
    {
        // _data->_window->close();
        _data->_states->addState(new maincharacter(_data));
    }
    else if (m_returnMainMenuPressed)
    {
        // // Implement your "Load Game" logic here
        // _data->_states->addState(new maincharacter(_data));
        _data->_states->addState(new menu(_data));
    }
}

void menuPause::draw()
{
    _data->_window->clear();
    _data->_window->draw(background);
    _data->_window->draw(m_gametitle);
    _data->_window->draw(m_resume);
    _data->_window->draw(m_returnMainMenu);
    _data->_window->display();
}