#include "inputNameHighScore.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

inputNameHighScore::inputNameHighScore(data *data) : _data(data)
{
}

inputNameHighScore::~inputNameHighScore()
{
}

void inputNameHighScore::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(BG_INPUT_NAME));
    backgroundSprite.setSize(sf::Vector2f(_data->_window->getSize().x, _data->_window->getSize().y));

    // countdownText.setFont(_data->_assets->getFont(MAIN_FONT));
    // countdownText.setCharacterSize(200);
    // countdownText.setFillColor(sf::Color::White);
    // countdownText.setOrigin(countdownText.getGlobalBounds().width / 2.f, countdownText.getGlobalBounds().height / 2.f);
    // countdownText.setPosition(_data->_window->getSize().x / 2.f, _data->_window->getSize().y / 2.f);
    // countdownText.setOutlineColor(_data->_assets->getThemeColor());
    // countdownText.setOutlineThickness(7.f);
}

void inputNameHighScore::processInput()
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
            case sf::Keyboard::Return:
                // _data->_states->addState(stateRef(new menuMain(_data)), true);
                break;
            default:
                break;
            }
        }
    }
}

void inputNameHighScore::update()
{
    // if (isPaused)
    // {

    //     if (clock.getElapsedTime().asSeconds() >= 1.f)
    //     {
    //         countdown--;
    //         clock.restart();
    //     }

    //     if (countdown <= 0)
    //     {
    //         isPaused = false;
    //         countdown = 3;
    //     }

    //     countdownText.setString(std::to_string(countdown));
    // }
    // else
    // {
    //     // game -> pause -> remove pause -> resume -> remove resume -> game
    //     _data->_states->removeState(false);
    // }
}

void inputNameHighScore::draw()
{
    _data->_window->clear();

    _data->_window->draw(backgroundSprite);
    //     _data->_window->draw(countdownText);
    // }

    _data->_window->display();
}

void inputNameHighScore::saveScore(const std::string &filename, const Player &player)
{
    std::vector<Player> players;

    // Read existing players from file
    std::ifstream inputFile(filename, std::ios::binary);
    Player inputPlayer;
    while (inputFile.read(reinterpret_cast<char *>(&inputPlayer), sizeof(Player)))
    {
        players.push_back(inputPlayer);
    }
    inputFile.close();

    // Add new player
    players.push_back(player);

    // Sort players by score
    std::sort(players.begin(), players.end());

    // If more than 10 players, remove the ones with the lowest scores
    while (players.size() > 10)
    {
        players.pop_back();
    }

    // Write all players back to file
    std::ofstream outputFile(filename, std::ios::binary);
    for (const Player &outputPlayer : players)
    {
        outputFile.write(reinterpret_cast<const char *>(&outputPlayer), sizeof(Player));
    }
}

void inputNameHighScore::printScores()
{
    std::ifstream inputFile(SCORES_PATH, std::ios::binary);
    Player player;

    for (int i = 0; i < NUM_SCORES; i++)
    {
        inputFile.read(reinterpret_cast<char *>(&player), sizeof(Player));
        // inputFile.read(reinterpret_cast<char *>(&player), sizeof(Player));
        // std::cout << player.name << " " << player.score << std::endl;
    }
}