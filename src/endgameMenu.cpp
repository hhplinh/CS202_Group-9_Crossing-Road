#include "endgameMenu.hpp"

#include "map.hpp"
#include "menu.hpp"

endgameMenu::endgameMenu(data *data)
    : _data(data), m_returnMainMenuSelected(false), m_returnMainMenuPressed(false), m_restartSelected(false), m_restartPressed(false)
{
}
endgameMenu::~endgameMenu() {}
void endgameMenu::init()
{
    background.setTexture(&_data->_assets->getTexture(BACKGROUND));

    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);

    // Title
    m_gametitle.setFont(_data->_assets->getFont(MAIN_FONT));
    m_gametitle.setString("CrossyRoad");
    m_gametitle.setOrigin(m_gametitle.getLocalBounds().width / 2,
                          m_gametitle.getLocalBounds().height / 2);
    m_gametitle.setPosition(_data->_window->getSize().x / 2,
                            _data->_window->getSize().y / 2 - 150.f);

    // Score
    score.setFont(_data->_assets->getFont(MAIN_FONT));
    // score.setString("Score: " + std::to_string());
    score.setString("Score: ");
    score.setOrigin(score.getLocalBounds().width / 2,
                    score.getLocalBounds().height / 2);
    score.setPosition(_data->_window->getSize().x / 2,
                      _data->_window->getSize().y / 2 - 75.f);

    // Restart Button
    m_restart.setFont(_data->_assets->getFont(MAIN_FONT));
    m_restart.setString("Restart");
    m_restart.setOrigin(m_restart.getLocalBounds().width / 2,
                        m_restart.getLocalBounds().height / 2);
    m_restart.setPosition(_data->_window->getSize().x / 2,
                          _data->_window->getSize().y / 2 - 25.f);
    m_restart.setCharacterSize(50);

    // Return main menu Button
    m_returnMainMenu.setFont(_data->_assets->getFont(MAIN_FONT));
    m_returnMainMenu.setString("Return to main menu");
    m_returnMainMenu.setOrigin(m_returnMainMenu.getLocalBounds().width / 2,
                               m_returnMainMenu.getLocalBounds().height / 2);
    m_returnMainMenu.setPosition(_data->_window->getSize().x / 2,
                                 _data->_window->getSize().y / 2 + 25.f);
    m_returnMainMenu.setCharacterSize(50);
}
void endgameMenu::processInput()
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
                if (!m_restartSelected && m_returnMainMenuSelected)
                {
                    m_restartSelected = true;
                    m_returnMainMenuSelected = false;
                }
                else if (m_restartSelected && !m_returnMainMenuSelected)
                {
                    m_returnMainMenuSelected = true;
                    m_restartSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_restartSelected && m_returnMainMenuSelected)
                {
                    m_restartSelected = true;
                    m_returnMainMenuSelected = false;
                }
                else if (m_restartSelected && !m_returnMainMenuSelected)
                {
                    m_returnMainMenuSelected = true;
                    m_restartSelected = false;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                m_restartPressed = false;
                m_returnMainMenuPressed = false;

                if (m_restartSelected)
                {
                    m_restartPressed = true;
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

void endgameMenu::update()
{
    if (m_restartSelected)
    {
        m_restart.setFillColor(sf::Color::Black);
        m_returnMainMenu.setFillColor(sf::Color::White);
    }
    if (m_returnMainMenuSelected)
    {
        m_returnMainMenu.setFillColor(sf::Color::Black);
        m_restart.setFillColor(sf::Color::White);
    }

    else if (m_restartPressed)
    {
        _data->_states->addState(new maincharacter(_data));
    }
    else if (m_returnMainMenuPressed)
    {
        // // Implement your "Load Game" logic here
        _data->_states->addState(new menu(_data));
    }
}

void endgameMenu::draw()
{
    _data->_window->clear();
    _data->_window->draw(background);
    _data->_window->draw(m_gametitle);
    _data->_window->draw(score);
    _data->_window->draw(m_restart);
    _data->_window->draw(m_returnMainMenu);
    _data->_window->display();
}