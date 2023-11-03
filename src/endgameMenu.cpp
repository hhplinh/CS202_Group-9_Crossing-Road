#include "endgameMenu.hpp"

#include "maincharacter.hpp"
#include "map.hpp"
#include "menu.hpp"

endgameMenu::endgameMenu(data *data) : menu(data)
{
    m_buttonsSelected.resize(NUM_BUTTONS, false);
    m_buttonsPressed.resize(NUM_BUTTONS, false);
    m_buttonsSelected[0] = true;
}

endgameMenu::~endgameMenu() {}

void endgameMenu::init()
{
    

    // set font, name and origin for each button
    std::cerr << "data end" << _data << std::endl;
    std::string buttonNames[NUM_BUTTONS];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        sf::Text button;
        button.setFont(_data->_assets->getFont(MAIN_FONT));
        buttonNames[i] = buttonToString[static_cast<Button>(i)];
        button.setString(buttonNames[i]);
        button.setOrigin(button.getLocalBounds().width / 2, button.getLocalBounds().height / 2);
        button.setCharacterSize(110);
        button.setPosition(1353, 400 + 150 * i);
        m_buttons.push_back(button);
    }

    m_buttons[MAIN_MENU].setPosition(1280, 400 + 150 * MAIN_MENU);

    score.setFont(_data->_assets->getFont(FONT2));
    // score.setString("Score: " + std::to_string(_data->_score));
    score.setString("Score: ");
    score.setOrigin(score.getLocalBounds().width / 2, score.getLocalBounds().height / 2);
    score.setCharacterSize(90);
    score.setPosition(1253, 254);

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

void endgameMenu::update()
{
    setColorSelect(m_buttons, m_buttonsSelected);

    if (m_buttonsPressed[RESTART])
    {
        m_buttonsPressed[RESTART] = false;
        _data->_states->removeStateUntilOne();
        _data->_states->addState(new maincharacter(_data));
    }
    else if (m_buttonsPressed[MAIN_MENU])
    {
        m_buttonsPressed[MAIN_MENU] = false;
        _data->_states->removeStateUntilOne();
    }
}

void endgameMenu::draw()
{
    _data->_window->clear();
    _data->_window->draw(background);
    _data->_window->draw(score);

    // condition for loading game, if there is no save file, the load game button will be disabled

    for (int i = 0; i < m_buttons.size(); i++)
    {
        _data->_window->draw(m_buttons[i]);
    }
    _data->_window->display();
}