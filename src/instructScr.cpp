#include "instructScr.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

instructScreen::instructScreen(data *data) : _data(data)
{
}

instructScreen::~instructScreen()
{
}
std::string instructScreen::loadTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return content;
}

void instructScreen::init()
{
    backgroundSprite.setTexture(&_data->_assets->getTexture(BACKGROUND2));
    backgroundSprite.setSize(sf::Vector2f(1920, 1080));
    backgroundSprite.setFillColor(sf::Color::White);

    std::string insText = loadTextFromFile(INSTRUCT_PATH);
    instructText.setFont(_data->_assets->getFont(MAIN_FONT));
    instructText.setCharacterSize(75);
    instructText.setFillColor(sf::Color::White);
    instructText.setOrigin(instructText.getGlobalBounds().width / 2.f, instructText.getGlobalBounds().height / 2.f);
    instructText.setString(insText);
    instructText.setPosition(500.f, 350.f);
    instructText.setOutlineColor(_data->_assets->getThemeColor());
    instructText.setOutlineThickness(7.f);

    board.setSize(sf::Vector2f(1150, 400));
    board.setPosition(sf::Vector2f(475, 330));
    board.setFillColor(sf::Color(255, 255, 255, 150));

}

void instructScreen::processInput()
{
    sf::Event event;
    while (_data->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _data->_window->close();
    }
}

void instructScreen::update()
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

void instructScreen::draw()
{
    _data->_window->clear();
    _data->_window->draw(backgroundSprite);
    _data->_window->draw(instructText);
    _data->_window->draw(board);
    //     _data->_window->draw(countdownText);
    // }
    _data->_window->display();
}


// int instructScr()
// {
    // Create a text
//     sf::Text text;
//     text.setFont(font);
//     text.setCharacterSize(24); // in pixels, not points!

//     // Read a file into a string
//     std::ifstream file("yourfile.txt");
//     std::stringstream buffer;
//     buffer << file.rdbuf();

//     // Set the string to the text
//     text.setString(buffer.str());

//     // Get the bounds of the text
//     sf::FloatRect textBounds = text.getLocalBounds();

//     // Calculate the scaling factors
//     float scaleX = window.getSize().x / textBounds.width;
//     float scaleY = window.getSize().y / textBounds.height;

//     // Use the smaller scale factor to ensure the text fits within the window
//     float scale = std::min(scaleX, scaleY);

//     // Scale the text
//     text.setScale(scale, scale);

//     // Center the text in the window
//     sf::Vector2f center(window.getSize().x / 2.f, window.getSize().y / 2.f);
//     text.setPosition(center.x - textBounds.width / 2.f, center.y - textBounds.height / 2.f);

//     // Game loop
//     while (window.isOpen())
//     {
//         // Process events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//             else if (event.type == sf::Event::Resized)
//             {
//                 // Recalculate the scale and position of the text
//                 scaleX = window.getSize().x / textBounds.width;
//                 scaleY = window.getSize().y / textBounds.height;
//                 scale = std::min(scaleX, scaleY);
//                 text.setScale(scale, scale);
//                 center = sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f);
//                 text.setPosition(center.x - textBounds.width / 2.f, center.y - textBounds.height / 2.f);
//             }
//         }

//         // Clear screen
//         window.clear();

//         // Draw the text
//         window.draw(text);

//         // Update the window
//         window.display();
//     }

//     return 0;
// }
