#pragma once

#include <components/Component.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

struct RangeComponent : public IComponent
{
    sf::RectangleShape range;

    RangeComponent()
    {
        Setup();
    }
    RangeComponent(float x, float y, float width, float height)
    {
        range.setPosition(x, y);
        range.setSize({ width, height });
        Setup();
    }
private:
    void Setup()
    {
        range.setFillColor(sf::Color::Transparent);
        range.setOutlineColor(sf::Color::Yellow);
        range.setOutlineThickness(1.0F);
    }
};