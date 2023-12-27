#include "maincharacter.hpp"
#pragma once

class maincharactereasy : public maincharacter
{
private:
public:
    maincharactereasy(data *_data) : maincharacter(_data) {}
    void update()
    {
        // Update the stamina first
        updateStamina();

        // Handle the fallen state
        /* if (stamina == 0 && !isFallen) {
             // Enter fallen state
             isFallen = true;
             moveCooldownTimer.restart();
             // Set the fallen texture
             p.setTextureRect(sf::IntRect(0, size.y*4, size.x, size.y));
         }
         else if (isFallen && moveCooldownTimer.getElapsedTime().asSeconds() >= 2.0f) {
             // Recover from fallen state
             isFallen = false;
             // Set the stand up texture or reset to initial sprite state
             p.setTextureRect(sf::IntRect(0, 0, size.x, size.y)); // Replace with appropriate texture rect for standing up
         }
     */
        // If the character has recovered from fallen, handle normal movement
        if (!isFallen)
        {
            move();
        }
        // Otherwise, ensure the character does not move
        else
        {
            // Additional logic for character in fallen state (if necessary)
        }
        processMovedDown();
    }

    void draw()
    {

        // _data->_window->clear();

        _data->_window->draw(p);
        // drawStaminaBar(*_data->_window);
        // _data->_window->display();
    }
};