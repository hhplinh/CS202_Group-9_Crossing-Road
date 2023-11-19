#include "menu.hpp"
#include "maincharacter.hpp"
#include "map.hpp"

#include "menuPause.hpp"
#include "endgameMenu.hpp"

menu::menu(data *data) : _data(data)
{
    _data->_assets->addTexture(BACKGROUND, "resources//Texture//bgMenu.png");
    _data->_assets->addTexture(ROAD, "resources//Texture//road.png");
    _data->_assets->addTexture(RIVER, "resources//Texture//River.png");
    _data->_assets->addFont(MAIN_FONT, "resources//Font//LilitaOne-Regular.ttf");
    _data->_assets->addFont(FONT2, "resources//Font//BlackOpsOne-Regular.ttf");
    _data->_assets->addTexture(GRASS, "resources//Texture//grass.png");
    _data->_assets->addTexture(CAR, "resources//Texture//Car 1.png");
    _data->_assets->addTexture(CAR2, "resources//Texture//Car 2.png");
    _data->_assets->addTexture(CAR3, "resources//Texture//Car 3.png");
    _data->_assets->addTexture(CAR4, "resources//Texture//Car 4.png");
    _data->_assets->addTexture(CAR5, "resources//Texture//Car 5.png");
    _data->_assets->addTexture(CANO, "resources//Texture//Cano.png");
    _data->_assets->addTexture(CANO2, "resources//Texture//Cano 2.png");
    _data->_assets->addTexture(COP, "resources//Texture//Cop.png");
    _data->_assets->addTexture(VOI, "resources//Texture//Voi.png");
    _data->_assets->addTexture(GAU, "resources//Texture//Gau.png");
    _data->_assets->addTexture(TEGIAC, "resources//Texture//Tegiac.png");
    _data->_assets->addTexture(LACDA, "resources//Texture//Lacda.png");
    _data->_assets->addTexture(PENGUIN, "resources//Texture//Penguin.png");
    background.setTexture(&_data->_assets->getTexture(BACKGROUND));
    background.setSize(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color::White);
}

menu::~menu() {}

void menu::draw()
{
    if (isEventChanged)
    {
        isEventChanged = 0;

        _data->_window->clear();

        _data->_window->draw(background);

        for (int i = 0; i < m_buttons.size(); i++)
        {
            _data->_window->draw(m_buttons[i]);
        }
        _data->_window->display();
    }
}

bool menu::isOnlyOneButtonOn(const std::vector<bool> &buttons)
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

void menu::turnOnButtonKeyDown(std::vector<bool> &m_buttonsSelected)
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

void menu::turnOnButtonKeyUp(std::vector<bool> &m_buttonsSelected)
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

void menu::turnOnButtonKeyEnter(std::vector<bool> &buttonsSelected, std::vector<bool> &buttonsPressed)
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

void menu::setColorSelect(std::vector<sf::Text> &m_buttons, std::vector<bool> &m_buttonsSelected, sf::Color COLOR_SELECT)
{
    for (int i = 0; i < m_buttons.size(); i++)
    {
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