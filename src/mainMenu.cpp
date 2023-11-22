#include "mainMenu.hpp"
#include "loadMapLevel.hpp"
#include "diffiMenu.hpp"
#include "map.hpp"

mainMenu::mainMenu(data *data) : menu(data)
{

    m_buttonsSelected.resize(NUM_BUTTONS, false);
    m_buttonsPressed.resize(NUM_BUTTONS, false);
    m_buttonsSelected[0] = true;
}

mainMenu::~mainMenu() {}

void mainMenu::init()
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
        button.setPosition(1475, 310 + 150 * i);
        m_buttons.push_back(button);
    }
}
void mainMenu::processInput()
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

void mainMenu::update()
{ 
    if (m_buttonsPressed[PLAY])
    {
        m_buttonsPressed[PLAY] = false;
        _data->_states->addState(new diffiMenu(_data));
    }
    else if (m_buttonsPressed[LOAD])
    {
        m_buttonsPressed[LOAD] = false;
        // Implement your "Load Game" logic here
        if (_data->_assets->isEasyLevelSavedGame() == true)
        {
            _data->_states->addState(new mapeasyLoad(_data));
        }
        else
        {
            _data->_states->addState(new mapLoad(_data));
        }
    }
    else if (m_buttonsPressed[SETTINGS])
    {
        m_buttonsPressed[SETTINGS] = false;
        // Implement your "Settings" logic here
    }
    else if (m_buttonsPressed[EXIT])
    {
        m_buttonsPressed[EXIT] = false;
        _data->_window->close();
    }
}
