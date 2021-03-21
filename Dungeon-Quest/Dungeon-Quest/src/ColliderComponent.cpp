#include <components/ColliderComponent.hpp>
#include <Defines.h>

ColliderComponent::ColliderComponent()
{
    Setup();
}

ColliderComponent::ColliderComponent(float x, float y, float width, float height)
{
    setPosition({ x, y - 2 });
    setSize({ abs(width - x) + TILE_SIZE, abs(height - y) + TILE_SIZE });
    Setup();
}

void ColliderComponent::Setup()
{
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::Green);
    setOutlineThickness(1.0f);
}