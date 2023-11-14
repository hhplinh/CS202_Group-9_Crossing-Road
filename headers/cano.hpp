#pragma once

#include "system.h"
#include <SFML/Graphics.hpp>

class Cano : public sf::Drawable {
private:
    bool isMovingRight;
    float speed;
    data* _data;
    sf::Sprite sprite;

public:
    Cano(data* _data);

    sf::FloatRect getGlobalBounds();
    void setPosCano(sf::Vector2f posRiver);
    void turnAround();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setSpeed(float speed);
    float getSpeed();
    void floatOnRiver();

    sf::Vector2f getPosCano();
};
