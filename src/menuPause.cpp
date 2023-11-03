#include "menuPause.hpp"

#include "maincharacter.hpp"
#include "map.hpp"

menuPause::menuPause(data *data) : _data(data), m_buttonsSelected(NUM_BUTTONS, false), m_buttonsPressed(NUM_BUTTONS, false)
{
    m_buttonsSelected[0] = true;
}
menuPause::~menuPause() {}

void menuPause::init()
{
    background.setTexture(&_data->_assets->getTexture(BACKGROUND));
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);

    // set font, name and origin for each button
    std::string buttonNames[NUM_BUTTONS];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        sf::Text button;
        button.setFont(_data->_assets->getFont(MAIN_FONT));
        buttonNames[i] = buttonToString[static_cast<Button>(i)];
        button.setString(buttonNames[i]);
        button.setOrigin(button.getLocalBounds().width / 2, button.getLocalBounds().height / 2);
        button.setCharacterSize(110);
        button.setPosition(1353, 254 + 150 * i);
        m_buttons.push_back(button);
    }

    m_buttons[MAIN_MENU].setPosition(1280, 254 + 150 * MAIN_MENU);
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
}

void menuPause::update()
{
    setColorSelect(m_buttons, m_buttonsSelected);

    if (m_buttonsPressed[RESUME])
    {
        m_buttonsPressed[RESUME] = false;
        _data->_states->removeState();
    }
    else if (m_buttonsPressed[MAIN_MENU])
    {
        m_buttonsPressed[MAIN_MENU] = false;
        _data->_states->removeStateUntilOne();
    }
}

void menuPause::draw()
{
    _data->_window->clear();
    _data->_window->draw(background);

    // condition for loading game, if there is no save file, the load game button will be disabled

    for (int i = 0; i < m_buttons.size(); i++)
    {
        _data->_window->draw(m_buttons[i]);
    }
    _data->_window->display();
}