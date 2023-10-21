#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

// Terrain Segment Types
enum class TerrainType { Road, River, Grass };

class TerrainSegment 
{
public:
    TerrainType type;
    RectangleShape shape;

    TerrainSegment(TerrainType t, float width, float height) : type(t) {
        shape.setSize(Vector2f(width, height));
        if (type == TerrainType::Road) {
            shape.setFillColor(Color::White);
        } else if (type == TerrainType::River) {
            shape.setFillColor(Color::Blue);
        } else {
            shape.setFillColor(Color::Green);
        }
    }
};
vector<TerrainSegment> terrainBuffer;
class TerrainGenerator 
{
public:
    std::vector<TerrainSegment> segments;
    float segmentWidth;
    float segmentHeight;
    float screenWidth;

    TerrainGenerator(float screenW, float segW, float segH) : screenWidth(screenW), segmentWidth(segW), segmentHeight(segH) {
        // Seed the random number generator
        srand(static_cast<unsigned>(time(nullptr)));
    }

    void generateTerrain() 
    {
        
        float x = 0.0f;

        while (x < screenWidth) 
        {
            TerrainType type = static_cast<TerrainType>(rand() % 3); // Randomly choose the terrain type
            TerrainSegment segment(type, segmentWidth, segmentHeight);
            segment.shape.setPosition(x, 0.0f);
            segments.push_back(segment);
            x += segmentWidth;
        }
    }

    void initializeTerrain() 
    {
        float x = 0.0f;

        while (x < screenWidth) 
        {
            TerrainType type = static_cast<TerrainType>(rand() % 3);
            TerrainSegment segment(type, segmentWidth, segmentHeight);
            segment.shape.setPosition(x, 0.0f);
            segments.push_back(segment);
            x += segmentWidth;
        }
    }

void updateTerrain(float characterXPosition, float screenWidth, float screenHeight) 
{
    // Calculate a threshold for generating new terrain segments
    float generateThreshold = screenWidth * 0.75; // Adjust as needed

    // Calculate a threshold for removing off-screen terrain segments
    float removeThreshold = -segmentWidth; // The left edge of the screen

    for (auto& segment : segments) {
        segment.shape.move(-0.1f, 0.0f); // Adjust the movement speed as needed

        // Check if the segment is off-screen and can be removed
        if (segment.shape.getPosition().x < removeThreshold) 
        {
            segments.erase(segments.begin());
        }
    }

    // Check if new terrain segments need to be generated
    if (characterXPosition > generateThreshold)
    {
        // Generate new terrain segments and add them to the segments vector
        TerrainType type = static_cast<TerrainType>(rand() % 3); // Randomly choose the terrain type
        TerrainSegment segment(type, segmentWidth, segmentHeight);
        segment.shape.setPosition(screenWidth, 0.0f);
        segments.push_back(segment);
    }
}


};
