#include "musicManager.h"

bool MusicManager::toggleMusic()
{
    if (music.getStatus() == sf::Music::Playing)
    {
        music.pause();
        return 0;
    }
    else
    {
        music.play();
        return 1;
    }
}

void MusicManager::playMusic()
{
    if (music.getStatus() != sf::Music::Playing)
    {
        music.play();
    }
}

MusicManager &MusicManager::getInstance()
{
    static MusicManager instance;
    return instance;
}

bool MusicManager::loadMusic(const std::string &filename)
{
    if (!music.openFromFile(filename))
    {
        return false;
    }
    return true;
}

void MusicManager::configureMusic(int volume, bool loop)
{
    music.setVolume(volume);
    music.setLoop(loop);
}

bool MusicManager::isPlaying() const
{
    return music.getStatus() == sf::Music::Playing;
}