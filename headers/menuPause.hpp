#pragma once
#include "state.h"
#include "system.h"
#include "map.hpp"
#include "maincharacter.hpp"
#include <ScreenMenu.hpp>

#include <memory>
#include <SFML/Graphics/Text.hpp>
class menuPause : public state
{
private:

    data *_data;
    sf::Sprite backgroundTexture;
    sf::RectangleShape background;
    sf::Text m_gametitle;
    sf::Text m_pause;
    sf::Text m_returnMainMenu;
    sf::Text m_resume;

    bool m_playselected;
    bool m_exitselected;
    bool m_playpressed;
    bool m_exitpressed;
    sf::Text m_loadGame;
    bool m_loadGameSelected;
    bool m_loadGamePressed;

    

public:
    menuPause(data *data);
    ~menuPause();
    void init();
    void processInput();
    void update();
    void draw();
};
