#pragma once
#include "state.h"
#include "system.h"
#include "map.hpp"
#include "maincharacter.hpp"

#include <memory>
#include <SFML/Graphics/Text.hpp>
class menuPause : public state
{
private:

    data *_data;
    sf::Sprite backgroundTexture;
    sf::RectangleShape background;
    sf::Text m_gametitle;
    sf::Text m_resume;
    sf::Text m_returnMainMenu;

    bool m_resumeSelected;
    bool m_resumePressed;

    bool m_returnMainMenuSelected;
    bool m_returnMainMenuPressed;

public:
    menuPause(data *data);
    ~menuPause();
    void init();
    void processInput();
    void update();
    void draw();
};
