#include "menuPause.hpp"

#include "maincharacter.hpp"
#include "map.hpp"

menuPause::menuPause(data *data)
    : _data(data), m_buttonsSelected(NUM_BUTTONS, false), m_buttonsPressed(NUM_BUTTONS, false)
{
    m_buttonsSelected[0] = true;
}
menuPause::~menuPause() {}

void menuPause::init()
{
    // _data->_assets->addTexture(BACKGROUND, "resources//Texture//bgMenu.png");
    // _data->_assets->addTexture(ROAD, "resources//Texture//River.png");
    // _data->_assets->addTexture(RIVER, "resources//Texture//road.png");

    // _data->_assets->addFont(MAIN_FONT, "resources//Font//LilitaOne-Regular.ttf");

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
        button.setPosition(1363, 254 + 90 * i);
        m_buttons.push_back(button);
    }
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

bool menuPause::isOnlyOneButtonOn(const std::vector<bool> &buttons)
{
    int count = 0;
    for (int i = 0; i < buttons.size(); i++)
    {
        if (buttons[i] == true)
        {
            ++count;
        }
    }
    return count == 1;
}

void menuPause::turnOnButtonKeyDown(std::vector<bool> &buttonsSelected)
{
    for (int i = 0; i < m_buttonsSelected.size(); i++)
    {
        if (m_buttonsSelected[i] == true)
        {
            m_buttonsSelected[i] = false;
            if (i == m_buttonsSelected.size() - 1)
            {
                m_buttonsSelected[0] = true;
            }
            else
            {
                m_buttonsSelected[i + 1] = true;
            }
            break;
        }
    }
}

void menuPause::turnOnButtonKeyUp(std::vector<bool> &m_buttonsSelected)
{
    for (int i = 0; i < m_buttonsSelected.size(); i++)
    {
        if (m_buttonsSelected[i] == true)
        {
            m_buttonsSelected[i] = false;
            if (i == 0)
            {
                m_buttonsSelected[m_buttonsSelected.size() - 1] = true;
            }
            else
            {
                m_buttonsSelected[i - 1] = true;
            }
            break;
        }
    }
}

void menuPause::turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed)
{
    for (int i = 0; i < buttonsSelected.size(); i++)
    {
        buttonsPressed[i] = false;
        if (buttonsSelected[i] == true)
        {
            buttonsPressed[i] = true;
        }
    }
}

void menuPause::setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected)
{
    for (int i = 0; i < m_buttons.size(); i++)
    {
        std::cerr << m_buttons.size() << std::endl;
        if (m_buttonsSelected[i])
        {
            m_buttons[i].setFillColor(COLOR_SELECT);
        }
        else
        {
            m_buttons[i].setFillColor(sf::Color::White);
        }
    }
}