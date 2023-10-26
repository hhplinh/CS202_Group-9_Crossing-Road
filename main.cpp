// #include <FrontendGlobal.hpp>
// #include <MainMenu.hpp>
#include "MainMenu.hpp"

int main()
{
    // float width = 800;
    // float height = 600;
    // mainMenu.create(width, height);
    // MainMenu mainMenu;
    MainMenu mainMenu;
    mainMenu.a();
    
    return 0;
}

// void run_test()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }
// }


// void runStudentManager()
// {
//     // Create a window with the size of 800x600 pixels
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Student Manager");

//     // Create a font object to be used for text rendering
//     sf::Font font;
//     if (!font.loadFromFile("Helvetica.ttf"))
//     {
//         // handle font loading error
//         return;
//     }

//     // Create a text object for the title
//     sf::Text title("Student Manager", font, 36);
//     title.setPosition(100, 50);

//     // Create a text box for the student's name
//     sf::RectangleShape nameBox(sf::Vector2f(300, 40));
//     nameBox.setPosition(100, 150);
//     sf::Text nameLabel("Name:", font, 24);
//     nameLabel.setPosition(100, 120);
//     sf::Text nameText("", font, 24);
//     nameText.setPosition(110, 155);

//     // Create a button to add a new student
//     sf::RectangleShape addButton(sf::Vector2f(100, 50));
//     addButton.setPosition(100, 220);
//     sf::Text addButtonText("Add", font, 24);
//     addButtonText.setPosition(130, 230);

//     // Create a list of students
//     sf::RectangleShape studentList(sf::Vector2f(400, 300));
//     studentList.setPosition(300, 150);

//     // Main loop
//     while (window.isOpen())
//     {
//         // Handle events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//             else if (event.type == sf::Event::TextEntered)
//             {
//                 // Handle typing in the name box
//                 if (event.text.unicode < 128)
//                 {
//                     nameText.setString(nameText.getString() + static_cast<char>(event.text.unicode));
//                 }
//             }
//             else if (event.type == sf::Event::MouseButtonPressed)
//             {
//                 // Handle button clicks
//                 if (addButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
//                 {
//                     // TODO: Add new student to list
//                 }
//             }
//         }

//         // Clear the window
//         window.clear(sf::Color::White);

//         // Draw the GUI elements
//         window.draw(title);
//         window.draw(nameBox);
//         window.draw(nameLabel);
//         window.draw(nameText);
//         window.draw(addButton);
//         window.draw(addButtonText);
//         window.draw(studentList);

//         // Display the window
//         window.display();
//     }
// }



// // #include <SFML/Graphics.hpp>
// #include <StudentManager.hpp>
// #include <FrontendGlobal.hpp>
// #include <BackendGlobal.hpp>
// #include <Password.hpp>
// #include <CoursesTable.hpp>
// #include <StudentWindow.hpp>

// class Circle : public sf::Drawable
// {
// public:
//     virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
//     {
//         sf::Sprite sprite(Texture.getTexture());
//         target.draw(sprite, states);
//     }

//     Circle()
//     {
//         circle_.setRadius(50.0f);
//         Texture.create(200, 200);
//         Texture.draw(circle_);
//     }

// private:
//     sf::RenderTexture Texture;
//     sf::CircleShape circle_;
//     sf::Text text;
// };

// // Windows
// // extern List<Backend::Course *> list;
// sf::Image icon;

// int main()
// {
// 	Backend::loadData();
	
//     // Initialize Window
//     window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100),
//                   "Student Manager",
//                   sf::Style::Default ^ sf::Style::Resize);
//     window.setPosition(sf::Vector2i(0, 0));
//     window.setFramerateLimit(60);

//     LeftWindowWidth = (window.getSize().x * 4) / 5;
//     RightWindowWidth = window.getSize().x - LeftWindowWidth;
//     BackgroundColor = sf::Color::White;

//     icon.loadFromFile("../resources/Logo/Exe's Logo.png");
//     window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

//     // Load Data

//     if (!Backend::loadData()) std::cerr << "Fail";

//     // Load Fonts
//     LoadFonts(RegularFont, BoldFont, MediumFont, LightFont, HeavyFont);

//     // Test

//     // LogIn LogInWindow;
//     LogInWindow.create();

//     // Student Window
//     StudentScreen.create();

//     // Admin Window
//     AdminScreen.create();

//     // Staff Window
//     StaffScreen.create();

//     ///////////////////////////////////////////////////////////////////////////////////////

//     while (window.isOpen())
//     {
//         sf::Mouse mouse;
//         sf::Vector2i MousePos = mouse.getPosition(window);
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             switch (event.type)
//             {
//             case sf::Event::Closed:
//                 window.close();
//                 break;
//             default:
//                 break;
//             }
//             if (!LogInWindow.isHidden())
//                 LogInWindow.processEvent(event);
//             if (!StudentScreen.isHidden())
//                 StudentScreen.processEvent(event);
//             if (!AdminScreen.isHidden())
//                 AdminScreen.processEvent(event);
//             if (!StaffScreen.isHidden())
//                 StaffScreen.processEvent(event);
//         }
//         // if (TestWindow.mouseOn(MousePos))
//         // {
//         //     cursor.loadFromSystem(sf::Cursor::Text);
//         //     window.setMouseCursor(cursor);
//         // }
//         // else
//         // {
//         //     cursor.loadFromSystem(sf::Cursor::Arrow);
//         //     window.setMouseCursor(cursor);
//         // }
//         window.clear(BackgroundColor);
//         // window.clear(sf::Color::Yellow);
//         if (!LogInWindow.isHidden())
//             window.draw(LogInWindow);
//         if (!StudentScreen.isHidden())
//             window.draw(StudentScreen);
//         if (!AdminScreen.isHidden())
//             window.draw(AdminScreen);
//         if (!StaffScreen.isHidden())
//             window.draw(StaffScreen);
//         window.display();
//     }
//     // Backend::saveData();
// }
