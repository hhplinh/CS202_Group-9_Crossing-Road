#pragma once
#include "state.h"
#include "system.h"
#include "map.hpp"
#include "maincharacter.hpp"

#include <memory>
#include <SFML/Graphics/Text.hpp>
class endgameMenu : public state
{
private:

    data *_data;
    sf::Sprite backgroundTexture;
    sf::RectangleShape background;
    sf::Text m_gametitle;
    sf::Text score;
    sf::Text m_restart;
    sf::Text m_returnMainMenu;

    bool m_returnMainMenuSelected;
    bool m_returnMainMenuPressed;

    bool m_restartSelected;
    bool m_restartPressed;

public:
    endgameMenu(data *data);
    ~endgameMenu();
    void init();
    void processInput();
    void update();
    void draw();
};
