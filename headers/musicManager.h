#pragma once
#include <SFML/Audio/Music.hpp>

class MusicManager
{
public:
    static MusicManager &getInstance();

    MusicManager(const MusicManager &) = delete;
    void operator=(const MusicManager &) = delete;

    bool toggleMusic();
    void playMusic();
    bool loadMusic(const std::string& filename);
    void configureMusic(int volume, bool loop);
    bool isPlaying() const;

private:
    sf::Music music;
    MusicManager() {}
};