#include "menu.hpp"

#include "maincharacter.hpp"
#include "map.hpp"

menu::menu(data *data)
    : _data(data), m_playselected(true), m_playpressed(false),
      m_exitselected(false), m_exitpressed(false),
      m_loadGameSelected(false), m_loadGamePressed(false)
{
}
menu::~menu() {}
void menu::init()
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

    // Play Button
    m_play.setFont(_data->_assets->getFont(MAIN_FONT));
    m_play.setString("Play");
    m_play.setOrigin(m_play.getLocalBounds().width / 2,
                     m_play.getLocalBounds().height / 2);
    m_play.setPosition(_data->_window->getSize().x / 2,
                       _data->_window->getSize().y / 2 - 25.f);
    m_play.setCharacterSize(50);

    // Exit Button
    m_exit.setFont(_data->_assets->getFont(MAIN_FONT));
    m_exit.setString("Exit");
    m_exit.setOrigin(m_exit.getLocalBounds().width / 2,
                     m_exit.getLocalBounds().height / 2);
    m_exit.setPosition(_data->_window->getSize().x / 2,
                       _data->_window->getSize().y / 2 + 25.f);
    m_exit.setCharacterSize(50);

    // Load button
    m_loadGame.setFont(_data->_assets->getFont(MAIN_FONT));
    m_loadGame.setString("Load Game");
    m_loadGame.setOrigin(m_loadGame.getLocalBounds().width / 2,
                         m_loadGame.getLocalBounds().height / 2);
    m_loadGame.setPosition(_data->_window->getSize().x / 2,
                           _data->_window->getSize().y / 2 + 75.f);
    m_loadGame.setCharacterSize(50);

    // Pause button
    m_loadGame.setFont(_data->_assets->getFont(MAIN_FONT));
    m_loadGame.setString("Load Game");
    m_loadGame.setOrigin(m_loadGame.getLocalBounds().width / 2,
                         m_loadGame.getLocalBounds().height / 2);
    m_loadGame.setPosition(_data->_window->getSize().x / 2,
                           _data->_window->getSize().y / 2 + -25.f);
    m_loadGame.setCharacterSize(50);
}
void menu::processInput()
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
                if (!m_playselected && m_exitselected && !m_loadGameSelected)
                {
                    m_playselected = true;
                    m_loadGameSelected = false;
                    m_exitselected = false;
                }
                else if (!m_loadGameSelected && m_playselected && !m_exitselected)
                {
                    m_loadGameSelected = true;
                    m_exitselected = false;
                    m_playselected = false;
                }
                else if (!m_exitselected && m_loadGameSelected && !m_playselected)
                {
                    m_exitselected = true;
                    m_playselected = false;
                    m_loadGameSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_playselected && m_loadGameSelected && !m_exitselected)
                {
                    m_playselected = true;
                    m_loadGameSelected = false;
                    m_exitselected = false;
                }
                else if (!m_loadGameSelected && m_exitselected && !m_playselected)
                {
                    m_loadGameSelected = true;
                    m_exitselected = false;
                    m_playselected = false;
                }
                else if (!m_exitselected && m_playselected && !m_loadGameSelected)
                {
                    m_loadGameSelected = false;
                    m_exitselected = true;
                    m_playselected = false;
                }

                break;
            }
            case sf::Keyboard::Return:
            {
                m_playpressed = false;
                m_exitpressed = false;
                m_loadGamePressed = false;

                if (m_playselected)
                {
                    m_playpressed = true;
                }
                else if (m_exitselected)
                {
                    m_exitpressed = true;
                }
                else if (m_loadGameSelected)
                {
                    m_loadGamePressed = true;
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

void menu::update()
{

    if (m_loadGameSelected)
    {
        m_loadGame.setFillColor(sf::Color::Black);
        m_play.setFillColor(sf::Color::White);
        m_exit.setFillColor(sf::Color::White);
    }
    if (m_playselected)
    {
        m_play.setFillColor(sf::Color::Black);
        m_exit.setFillColor(sf::Color::White);
        m_loadGame.setFillColor(sf::Color::White);
    }
    if (m_exitselected)
    {
        m_exit.setFillColor(sf::Color::Black);
        m_play.setFillColor(sf::Color::White);
        m_loadGame.setFillColor(sf::Color::White);
    }
    if (m_playpressed)
    {
        _data->_states->addState(new maincharacter(_data));
    }
    else if (m_exitpressed)
    {
        _data->_window->close();
    }
    else if (m_loadGamePressed)
    {
        // Implement your "Load Game" logic here
        _data->_states->addState(new maincharacter(_data));
    }
}

void menu::draw()
{
    m_play.setFillColor(sf::Color::Black);
    m_exit.setFillColor(sf::Color::White);
    m_loadGame.setFillColor(sf::Color::White);
}
if(m_exitselected)
{
    m_exit.setFillColor(sf::Color::Black);
    m_play.setFillColor(sf::Color::White);
    m_loadGame.setFillColor(sf::Color::White);
}
if (m_playpressed)
{   
    _data->_states->addState(new maincharacter(_data));
    m_playpressed = false;
}
 if (m_exitpressed)
{
    _data->_window->close();
}
 if (m_loadGamePressed)
{
    // Implement your "Load Game" logic here
     _data->_states->addState(new maincharacter(_data));
    m_loadGamePressed = false;
}
}



void menu::draw(){
   _data->_window->clear();
 
    _data->_window->draw(background);
    _data->_window->draw(m_gametitle);
    _data->_window->draw(m_loadGame);
    _data->_window->draw(m_play);
    _data->_window->draw(m_exit);
    _data->_window->display();
}