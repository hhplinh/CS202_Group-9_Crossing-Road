#include "GameLevel.hpp"

TerrainGenerator::TerrainGenerator() {
    // Load textures for grass, rock, and river tiles
    grassTexture.loadFromFile("grass_texture.png");
    rockTexture.loadFromFile("rock_texture.png");
    riverTexture.loadFromFile("river_texture.png");

    // Generate initial terrain (for demonstration purposes)
    for (int i = 0; i < 100; ++i) {
        Tile::TerrainType type = static_cast<Tile::TerrainType>(rand() % 3);
        sf::Texture& texture = (type == Tile::Grass) ? grassTexture :
            (type == Tile::Rock) ? rockTexture : riverTexture;

        tiles.emplace_back(type, texture, 0, i * texture.getSize().y); // Adjust X position as needed
    }
}

void TerrainGenerator::update(float playerY, float windowHeight) {
    // Scroll the terrain based on the player's position
    float yOffset = playerY - windowHeight / 2;
    for (auto& tile : tiles) {
        sf::Sprite& sprite = tile.getSprite();
        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - yOffset);

        // Reposition tiles that go off-screen to create the actual scrolling effect
        if (sprite.getPosition().y + sprite.getLocalBounds().height < 0) {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + tiles.size() * sprite.getLocalBounds().height);
        }
        else if (sprite.getPosition().y > windowHeight) {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - tiles.size() * sprite.getLocalBounds().height);
        }
    }
}

void TerrainGenerator::draw(sf::RenderWindow& window) {
    for (auto& tile : tiles) {
        window.draw(tile.getSprite());
    }
}
