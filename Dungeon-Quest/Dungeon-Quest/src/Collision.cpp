#include <Collision.hpp>

#include <Defines.h>

CollisionBox::CollisionBox()
{
    Setup();
}

CollisionBox::CollisionBox(float x, float y, float width, float height)
{
    setPosition({ x, y });
    setSize({ abs(width - x) + TILE_SIZE, abs(height - y) + TILE_SIZE });
    Setup();
}

void CollisionBox::Setup()
{
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::Green);
    setOutlineThickness(1.0f);
}