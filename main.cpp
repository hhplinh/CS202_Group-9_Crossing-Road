#include <SFML/Graphics.hpp>
#include"player.hpp"
#include"MAINMENU.h"
#include"terrain.hpp"
int main() {
    float characterX = 0.0f;
    const int windowWidth = 800;
    const int windowHeight = 600;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Terrain Generation");

    const float segmentWidth = 100.0f;
    const float segmentHeight = static_cast<float>(windowHeight);

    TerrainGenerator terrainGenerator(static_cast<float>(windowWidth), segmentWidth, segmentHeight);
    terrainGenerator.initializeTerrain();
    terrainGenerator.generateTerrain();

    player p("resources/player.png");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

     ;

        // Draw terrain segments
        for (const TerrainSegment& segment : terrainGenerator.segments) 
        {
            window.draw(segment.shape);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            p.move('u', 0.3);
        } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            p.move('d', 0.3);
        } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            p.move('l', 0.3);
            characterX -= 0.3f;
        } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            p.move('r', 0.3);
            characterX += 0.3f;
        } else if (Keyboard::isKeyPressed(Keyboard::Space)) {
            p.hopping();
        } else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        } else if (Keyboard::isKeyPressed(Keyboard::A)) {
            p.hopleft();
        } else if (Keyboard::isKeyPressed(Keyboard::D)) {
            p.hopright();
        }

        // Update and draw the terrain based on the character's position
        terrainGenerator.updateTerrain(characterX, windowWidth, windowHeight);
        for (const TerrainSegment& segment : terrainGenerator.segments) 
        {
            window.draw(segment.shape);
        }

        // Draw the player
        p.draw(window);

        // Display the window
        window.display();
    }

    return 0;
}
//     }