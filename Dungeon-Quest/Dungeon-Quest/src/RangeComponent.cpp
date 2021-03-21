#include <components/RangeComponent.hpp>

RangeComponent::RangeComponent()
{
    Setup();
}

RangeComponent::RangeComponent(float x, float y, float width, float height)
{
    setPosition(x, y);
    setSize({ width, height });
    Setup();
}

void RangeComponent::Setup()
{
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::Yellow);
    setOutlineThickness(1.0f);
}