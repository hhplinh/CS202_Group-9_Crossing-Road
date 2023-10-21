#include<iostream>
#include<SFML/Graphics.hpp>

class Tile {
public:
    enum TerrainType { Grass, Rock, River };

    Tile(TerrainType terrainType, const sf::Texture& texture, float x, float y)
        : type(terrainType), sprite(texture) {
        sprite.setPosition(x, y);
    }

    TerrainType getType() const { return type; }
    sf::Sprite& getSprite() { return sprite; }

private:
    TerrainType type;
    sf::Sprite sprite;
};

class TerrainGenerator {
public:
    TerrainGenerator();

    void update(float playerY, float windowHeight);
    void draw(sf::RenderWindow& window);

private:
    std::vector<Tile> tiles;
    sf::Texture grassTexture, rockTexture, riverTexture;

    // Other variables for terrain generation can be added here
};

