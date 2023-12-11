#include "Leaderboard.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Leaderboard::Leaderboard(data *data) : _data(data)
{
   
}


Leaderboard::~Leaderboard()
{
}

std::vector<Player> loadPlayerData(const std::string& filename) {
    std::vector<Player> players;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return players;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Player player;

        if (iss >> player.name >> player.highScore) {
            players.push_back(player);
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return players;
}

void Leaderboard::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(LEADERBOARD));
    backgroundSprite.setSize(sf::Vector2f(1920, 1080));

    std::vector<Player> players = loadPlayerData("highScore.txt");
    if (!players.empty())
    {
        for (int i = 0; i < players.size(); i++)
        {
            playerNameText.emplace_back();
            playerScoreText.emplace_back();

            sf::Text& nameText = playerNameText.back();
            sf::Text& scoreText = playerScoreText.back();

            nameText.setFont(_data->_assets->getFont(MAIN_FONT));
            nameText.setCharacterSize(55);
            nameText.setFillColor(sf::Color::White);
            nameText.setOutlineColor(_data->_assets->getThemeColor());
            nameText.setOutlineThickness(5.f);
            nameText.setOrigin(nameText.getGlobalBounds().width / 2.f, nameText.getGlobalBounds().height / 2.f);

            scoreText.setFont(_data->_assets->getFont(MAIN_FONT));
            scoreText.setCharacterSize(55);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setOutlineColor(_data->_assets->getThemeColor());
            scoreText.setOutlineThickness(5.f);
            scoreText.setOrigin(scoreText.getGlobalBounds().width / 2.f, scoreText.getGlobalBounds().height / 2.f);

            nameText.setPosition(_data->_window->getSize().x / 2.f - 225, _data->_window->getSize().y / 2.f -150 + i * 128);
            scoreText.setPosition(_data->_window->getSize().x / 2.f + 210, _data->_window->getSize().y / 2.f -150 + i * 128);

            nameText.setString(players[i].name);
            scoreText.setString(std::to_string(players[i].highScore));

            //playerNameText.push_back(nameText);
           // playerScoreText.push_back(scoreText);
            /*playerNameText.setString(playerNameText.getString()  + players[i].name + "\n" + "\n");
            playerScoreText.setString(playerScoreText.getString() + std::to_string(players[i].highScore) + "\n" + "\n");
            playerNameText.setFont(_data->_assets->getFont(MAIN_FONT));
            playerNameText.setCharacterSize(55);
            playerNameText.setFillColor(sf::Color::White);
            playerNameText.setOutlineColor(_data->_assets->getThemeColor());
            playerNameText.setOutlineThickness(5.f);
            playerNameText.setOrigin(playerNameText.getGlobalBounds().width / 2.f, playerNameText.getGlobalBounds().height / 2.f);

            playerScoreText.setFont(_data->_assets->getFont(MAIN_FONT));
            playerScoreText.setCharacterSize(55);
            playerScoreText.setFillColor(sf::Color::White);
            playerScoreText.setOutlineColor(_data->_assets->getThemeColor());
            playerScoreText.setOutlineThickness(5.f);
            playerScoreText.setOrigin(playerScoreText.getGlobalBounds().width / 2.f, playerScoreText.getGlobalBounds().height / 2.f);
            playerNameText.setPosition(_data->_window->getSize().x / 2.f - 65, _data->_window->getSize().y / 2.f + 185);
            playerScoreText.setPosition(_data->_window->getSize().x / 2.f + 255, _data->_window->getSize().y / 2.f + 192);*/
        }
    }
}

void Leaderboard::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                _data->_states->removeStateUntilOne();
                break;
            default:
                break;
            }
        }
    }
}

void Leaderboard::update()
{
}



void Leaderboard::draw()
{
    _data->_window->clear();

    _data->_window->draw(backgroundSprite);
    std::vector<Player> players = loadPlayerData("highScore.txt");
 /*   _data->_window->draw(playerNameText);
    _data->_window->draw(playerScoreText);*/
    for (int i = 0; i < players.size(); i++)
    {
        _data->_window->draw(playerNameText[i]);
        _data->_window->draw(playerScoreText[i]);
    }
    //     _data->_window->draw(countdownText);
    // }
    
    _data->_window->display();
}
