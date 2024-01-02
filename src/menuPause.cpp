#include "menuPause.hpp"
#include "resumeScreen.hpp"
#include <SFML/System.hpp>

menuPause::menuPause(data *data) : menu(data)
{
    m_buttonsSelected.resize(NUM_BUTTONS, false);
    m_buttonsPressed.resize(NUM_BUTTONS, false);
    m_buttonsSelected[0] = true;
}

menuPause::~menuPause() {}

void menuPause::init()
{
    if (!m_buttons.empty())
    {
        return;
    }

    background.setTexture(&_data->_assets->getTexture(BACKGROUND));
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);

    std::string buttonNames[NUM_BUTTONS];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        sf::Text button;
        button.setFont(_data->_assets->getFont(MAIN_FONT));
        buttonNames[i] = buttonToString[static_cast<Button>(i)];
        button.setString(buttonNames[i]);
        button.setCharacterSize(110);
        button.setOrigin(button.getLocalBounds().width / 2, button.getLocalBounds().height / 2);
        button.setPosition(1475, 430 + 150 * i);
        m_buttons.push_back(button);
    }
}
void menuPause::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        isEventChanged = 1;
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
                if (isOnlyOneButtonOn(m_buttonsSelected))
                {
                    turnOnButtonKeyUp(m_buttonsSelected);
                }
                break;
            }

            case sf::Keyboard::Down:
            {
                if (isOnlyOneButtonOn(m_buttonsSelected))
                {
                    turnOnButtonKeyDown(m_buttonsSelected);
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                turnOnButtonKeyEnter(m_buttonsSelected, m_buttonsPressed);
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    setColorSelect(m_buttons, m_buttonsSelected);
}

void menuPause::update()
{

    if (m_buttonsPressed[RESUME])
    {
        m_buttonsPressed[RESUME] = false;
        
        _data->_states->removeState(false);
        _data->_states->addState(new ResumeScreen(_data));
    }
    else if (m_buttonsPressed[MAIN_MENU])
    {
        m_buttonsPressed[MAIN_MENU] = false;
        _data->_states->removeStateUntilOne();
    }
}