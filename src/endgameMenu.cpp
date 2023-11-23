#include "diffiMenu.hpp"
#include "endgameMenu.hpp"

endgameMenu::endgameMenu(data *data) : menu(data)
{
    m_buttonsSelected.resize(NUM_BUTTONS, false);
    m_buttonsPressed.resize(NUM_BUTTONS, false);
    m_buttonsSelected[0] = true;

    std::cerr << "endgameMenu constructor\n";
}

endgameMenu::~endgameMenu() {}

void endgameMenu::init()
{
    std::cerr << "endgameMenu init\n";
    if (!m_buttons.empty())
    {
        return;
    }


    // set font, name and origin for each button
    std::string buttonNames[NUM_BUTTONS];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        sf::Text button;
        button.setFont(_data->_assets->getFont(MAIN_FONT));
        buttonNames[i] = buttonToString[static_cast<Button>(i)];
        button.setString(buttonNames[i]);
        button.setCharacterSize(110);
        button.setOrigin(button.getLocalBounds().width / 2.f, button.getLocalBounds().height / 2.f);
        button.setPosition(1475, 410 + 150 * i);
        m_buttons.push_back(button);
    }

    score.setFont(_data->_assets->getFont(FONT2));
    // score.setString("Score: " + std::to_string(_data->_score));

    score.setString("Score: ");
    score.setCharacterSize(90);
    score.setOrigin(score.getLocalBounds().width / 2, score.getLocalBounds().height / 2);
    score.setPosition(1475, 260);
}

void endgameMenu::processInput()
{
    std::cerr << "\nin endgameMenu processInput\n";

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

    std::cerr << "out endgameMenu processInput\n";
}

void endgameMenu::update()
{
    std::cerr << "in endgameMenu update\n";
    if (m_buttonsPressed[RESTART])
    {
        m_buttonsPressed[RESTART] = false;
        _data->_states->removeStateUntilOne();
        _data->_states->addState(new diffiMenu(_data));
    }
    else if (m_buttonsPressed[MAIN_MENU])
    {
        m_buttonsPressed[MAIN_MENU] = false;
        _data->_states->removeStateUntilOne();
    }
    std::cerr << "endgameMenu update\n";
}

void endgameMenu::draw()
{
    std::cerr << "in endgameMenu draw\n";
    if (isEventChanged)
    {
        isEventChanged = 0;

        _data->_window->clear();
        _data->_window->draw(background);
        _data->_window->draw(score);

        for (int i = 0; i < m_buttons.size(); i++)
        {
            _data->_window->draw(m_buttons[i]);
        }
        
        _data->_window->display();
    }

    std::cerr << "endgameMenu draw\n";
}