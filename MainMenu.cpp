#include <MainMenu.hpp>

void MainMenu::create(float width, float height)
{
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::Text text;
        text.setFont(font);
        text.setString("Error loading font");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(sf::Vector2f(10, 10));
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
            }
            window.clear();
            window.draw(text);
            window.display();
        }
    }

    menu.resize(MAX_NUMBER_OF_ITEMS);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Credits");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    selectedItemIndex = -1;
}

void MainMenu::a()
{
    std::cerr << "a";
}

void MainMenu::renderNavigateWithButtons()
{
    create(960, 720);
    sf::RenderWindow MENU(sf::VideoMode(960, 720), "Main Menu", sf::Style::Default);
    MainMenu mainMenu;
    mainMenu.create(MENU.getSize().x, MENU.getSize().y);

    //set background
    sf::Texture texture;
    sf::RectangleShape background;

    //insert image
    texture.loadFromFile("../resources/Textures/bgMenu.jpg");

    background.setSize(sf::Vector2f(960, 720));
    background.setTexture(&texture);

    // run the main MENU
    while (MENU.isOpen())
    {
        // check for events
        sf::Event event;
        while (MENU.pollEvent(event))
        {
            // if the event is close, close the MENU
            if (event.type == sf::Event::Closed)
            {
                MENU.close();
            }

            // if the event is keyreleased
            if (event.type == sf::Event::KeyReleased)
            {
                // if the key is escape
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }

                if (event.key.code == sf::Keyboard::Return)
                {
                    sf::RenderWindow PLAY(sf::VideoMode(960, 720), "Road Crossing Game");

                    int x = mainMenu.GetPressedItem();
                    if (x == 0)
                    {
                        while (PLAY.isOpen())
                        {
                            sf::Event playEvent;
                            while (PLAY.pollEvent(playEvent))
                            {
                                if (playEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                                {
                                    PLAY.close();
                                }
                            }
                            PLAY.clear();
                            PLAY.display();
                        }
                    }

                    if (x == 1)
                    {
                        sf::RenderWindow OPTIONS(sf::VideoMode(960, 720), "Options");
                        while (OPTIONS.isOpen())
                        {
                            sf::Event optionsEvent;
                            while (OPTIONS.pollEvent(optionsEvent))
                            {
                                if (optionsEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                                {
                                    OPTIONS.close();
                                }
                            }
                            OPTIONS.clear();
                            OPTIONS.display();
                        }
                    }

                    if (x == 2)
                    {
                        sf::RenderWindow CREDITS(sf::VideoMode(960, 720), "Credits");
                        while (CREDITS.isOpen())
                        {
                            sf::Event creditsEvent;
                            while (CREDITS.pollEvent(creditsEvent))
                            {
                                if (creditsEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                                {
                                    CREDITS.close();
                                }
                            }
                            CREDITS.clear();
                            CREDITS.display();
                        }
                    }

                    if (x == 3)
                    {
                        MENU.close();
                    }
                }
            }
        }
        // clear the MENU
        MENU.clear();
        // draw the main menu
        mainMenu.draw(MENU);
        // display the MENU
        MENU.display();
    }
}

void MainMenu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void MainMenu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        if (selectedItemIndex == -1)
        {
            selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
        }
        menu[selectedItemIndex].setFillColor(sf::Color::Blue);
    }
}

void MainMenu::MoveDown()
{
    if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        if (selectedItemIndex == MAX_NUMBER_OF_ITEMS)
        {
            selectedItemIndex = 0;
        }
        menu[selectedItemIndex].setFillColor(sf::Color::Blue);
    }
}

int MainMenu::GetPressedItem()
{
    return selectedItemIndex;
}
