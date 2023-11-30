#pragma once
#include "state.h"
#include "system.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Music : public state {
private:
    sf::RenderWindow window;
    sf::Music backgroundMusic;
    data* _data;
    const std::string MUSIC_PATH = "resources//BackgroundMusic.ogg";

public:
    void init() {
        if (!backgroundMusic.openFromFile("background_music.ogg")) {
            std::cerr << "Failed to load background music!" << std::endl;
        }

        backgroundMusic.setVolume(50);
        backgroundMusic.setLoop(true);
    }
    Music(data* data) : _data(data) {}
    ~Music() {}
    void processInput()
    {
        sf::Event event;
        while (_data->_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _data->_window->close();
        }
    }
    void update();
    void draw()
    {
        if (sf::Music::Playing != backgroundMusic.getStatus()) {
            backgroundMusic.play();
        }
    }
};
