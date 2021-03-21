#include <components/DetectionComponent.hpp>

DetectionComponent::DetectionComponent()
{
    Setup();
}

DetectionComponent::DetectionComponent(float x, float y, float width, float height)
{
    setPosition(x, y);
    setSize({ width, height });
    Setup();
}

void DetectionComponent::Setup()
{
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::Red);
    setOutlineThickness(1.0f);
}