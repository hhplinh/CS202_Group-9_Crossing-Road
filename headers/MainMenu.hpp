#pragma once

#include "menu.hpp"
#include <map>

class mainMenu : public menu
{
private:

    enum Button
    {
        PLAY,
        LOAD,
        INSTRUCTION,
        EXIT,
        NUM_BUTTONS
    };
        // PAUSE,
        // END,

    std::map<Button, std::string> buttonToString = {
        {PLAY, "Play"},
        {LOAD, "Load"},
        {INSTRUCTION, "Instruction"},
        {EXIT, "Exit"},
    };

public:

    mainMenu(data *data);
    ~mainMenu();
    void init();
    void processInput();
    void update();
};

// #include <SFML/Graphics.hpp>
// #include <iostream>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf"))
//     {
//         std::cout << "Error loading font\n" ;
//         return 1;
//     }

//     std::string messageStr;
//     sf::Text messageText("", font, 30);
//     messageText.setPosition(10, 10);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//             else if (event.type == sf::Event::TextEntered)
//             {
//                 if (event.text.unicode < 128)
//                 {
//                     messageStr += static_cast<char>(event.text.unicode);
//                     messageText.setString(messageStr);
//                 }
//             }
//         }

//         window.clear();
//         window.draw(messageText);
//         window.display();
//     }

//     return 0;
// }
