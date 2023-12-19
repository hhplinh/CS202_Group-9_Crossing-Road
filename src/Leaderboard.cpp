#include "Leaderboard.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Leaderboard::Leaderboard(data *data) : _data(data)
{
    isEventChanged = true;
}

Leaderboard::~Leaderboard()
{
}

std::vector<Player> loadPlayerData(const std::string &filename)
{
    std::vector<Player> players;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return players;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        Player player;

        if (iss >> player.name >> player.highScore)
        {
            players.push_back(player);
        }
        else
        {
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

    std::vector<Player> players = loadPlayerData(SCORES_PATH);
    if (!players.empty())
    {
        for (int i = 0; i < players.size(); i++)
        {
            sf::Text nameText;
            sf::Text scoreText;

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

            nameText.setPosition(_data->_window->getSize().x / 2.f - 225, _data->_window->getSize().y / 2.f - 150 + i * 128);
            scoreText.setPosition(_data->_window->getSize().x / 2.f + 210, _data->_window->getSize().y / 2.f - 150 + i * 128);

            nameText.setString(players[i].name);
            scoreText.setString(std::to_string(players[i].highScore));

            playerNameText.push_back(nameText);
            playerScoreText.push_back(scoreText);
        }
    }
}

void Leaderboard::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        isEventChanged = true;
        if (event.type == sf::Event::Closed)
            _data->_window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                _data->_states->removeStateUntilOne();
                break;
            case sf::Keyboard::Enter:
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
    if (isEventChanged)
    {
        isEventChanged = false;
        _data->_window->clear();

        _data->_window->draw(backgroundSprite);
        // std::vector<Player> players = loadPlayerData(SCORES_PATH);
        int len = playerNameText.size();
        for (int i = 0; i < len; i++)
        {
            _data->_window->draw(playerNameText[i]);
            _data->_window->draw(playerScoreText[i]);
        }

        _data->_window->display();
    }
}
