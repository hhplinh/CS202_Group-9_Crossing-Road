#include "mainMenu.hpp"
#include "maincharacter.hpp"
#include "map.hpp"

#include "menuPause.hpp"
#include "endgameMenu.hpp"

mainMenu::mainMenu(data *data) : menu(data)
{
    // std::cerr << "construct main menu" << std::endl;

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
        button.setOrigin(button.getLocalBounds().width / 2, button.getLocalBounds().height / 2);
        button.setCharacterSize(110);
        button.setPosition(1393, 254 + 150 * i);
        m_buttons.push_back(button);
    }

    // set pos for setting button
    m_buttons[SETTINGS].setPosition(1333, 254 + 150 * SETTINGS);
}
void mainMenu::processInput()
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
    setColorSelect(m_buttons, m_buttonsSelected);
}

void mainMenu::update()
{   // player->update();
    if (m_buttonsPressed[PLAY])
    {
        m_buttonsPressed[PLAY] = false;
        //_data->_states->addState(new maincharacter(_data));
    }
    else if (m_buttonsPressed[EXIT])
    {
        m_buttonsPressed[EXIT] = false;
        _data->_window->close();
    }
    else if (m_buttonsPressed[LOAD])
    {
        m_buttonsPressed[LOAD] = false;
        // Implement your "Load Game" logic here
        _data->_states->addState(new map(_data));
    }
    else if (m_buttonsPressed[SETTINGS])
    {
        m_buttonsPressed[SETTINGS] = false;
        // Implement your "Settings" logic here
    }

    // test section

    // else if (m_buttonsPressed[PAUSE])
    // {
    //     m_buttonsPressed[PAUSE] = false;
    //     _data->_states->addState(new menuPause(_data));
    // }
    // else if (m_buttonsPressed[END])
    // {
    //     m_buttonsPressed[END] = false;
    //     _data->_states->addState(new endgameMenu(_data));
    // }
}

void mainMenu::draw()
{
    _data->_window->clear();
    //player->draw();
    _data->_window->draw(background);

    // condition for loading game, if there is no save file, the load game button will be disabled

    for (int i = 0; i < m_buttons.size(); i++)
    {
        _data->_window->draw(m_buttons[i]);
    }
   
    _data->_window->display();
}