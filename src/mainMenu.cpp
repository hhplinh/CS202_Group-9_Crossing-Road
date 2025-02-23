#include "mainMenu.hpp"
#include "loadMapLevel.hpp"
#include "leaderboard.hpp"
#include "diffiMenu.hpp"
#include "instructScr.hpp"
#include "MainMenu0Load.hpp"
#include "musicManager.h"
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
        button.setCharacterSize(100);
        button.setOrigin(button.getLocalBounds().width / 2.f, button.getLocalBounds().height / 2.f);
        button.setPosition(1470, 220 + 130 * i);
        m_buttons.push_back(button);
    }

    initMusicText(m_buttons[MUSIC_ON], MusicManager::getInstance().isPlaying());
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
    if (_data->_assets->isGameSaved() == false)
    {
        _data->_states->addState(new mainMenu0Load(_data), true);
    }
    else if (m_buttonsPressed[PLAY])
    {
        m_buttonsPressed[PLAY] = false;
        _data->_states->addState(new diffiMenu(_data));
    }
    else if (m_buttonsPressed[LOAD])
    {
        m_buttonsPressed[LOAD] = false;
        if (_data->_assets->isEasyLevelSavedGame() == true)
        {
            _data->_states->addState(new mapeasyLoad(_data));
        }
        else
        {
            _data->_states->addState(new mapLoad(_data));
        }
    }
    else if (m_buttonsPressed[LEADERBOARD])
    {
        m_buttonsPressed[LEADERBOARD] = false;
        _data->_states->addState(new Leaderboard(_data));
    }
    else if (m_buttonsPressed[INSTRUCTION])
    {
        m_buttonsPressed[INSTRUCTION] = false;
        _data->_states->addState(new instructScreen(_data));
    }
    else if (m_buttonsPressed[MUSIC_ON])
    {
        m_buttonsPressed[MUSIC_ON] = false;
        toggleMusicText(m_buttons[MUSIC_ON], MusicManager::getInstance().toggleMusic());
    }
    else if (m_buttonsPressed[EXIT])
    {
        m_buttonsPressed[EXIT] = false;
        _data->_window->close();
    }
}
