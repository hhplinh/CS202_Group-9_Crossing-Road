#include "diffiMenu.hpp"
#include "maincharacter.hpp"
#include "mapKid.h"

diffiMenu::diffiMenu(data *data) : menu(data)
{
    m_buttonsSelected.resize(NUM_BUTTONS, false);
    m_buttonsPressed.resize(NUM_BUTTONS, false);
    m_buttonsSelected[0] = true;

    isEventChanged = 1;
}

diffiMenu::~diffiMenu() {}

void diffiMenu::init()
{
    if (!m_buttons.empty())
    {
        return;
    }

    std::string buttonNames[NUM_BUTTONS];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        sf::Text button;
        button.setFont(_data->_assets->getFont(MAIN_FONT));
        buttonNames[i] = buttonToString[static_cast<Button>(i)];
        button.setString(buttonNames[i]);
        button.setCharacterSize(110);
        button.setOrigin(button.getLocalBounds().width / 2.f, button.getLocalBounds().height / 2.f);
        button.setPosition(1470, 300 + 150 * i);
        m_buttons.push_back(button);
    }
}
void diffiMenu::processInput()
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

void diffiMenu::update()
{
    if (m_buttonsPressed[KID])
    {
        m_buttonsPressed[KID] = false;
        _data->_states->addState(new mapKid(_data));
    }
    else if (m_buttonsPressed[EASY])
    {
        m_buttonsPressed[EASY] = false;
        _data->_states->addState(new mapeasy(_data));
    }
    else if (m_buttonsPressed[DIFFICULT])
    {
        m_buttonsPressed[DIFFICULT] = false;
        _data->_states->addState(new map(_data));
    }
    else if (m_buttonsPressed[BACK])
    {
        m_buttonsPressed[BACK] = false;
        _data->_states->removeState();
    }
}