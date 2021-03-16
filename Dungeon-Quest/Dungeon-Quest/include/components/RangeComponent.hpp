#pragma once

#include <SFML/Graphics.hpp>

struct RangeComponent : public sf::RectangleShape
{
    RangeComponent()
    {
        Setup();
    }
    RangeComponent(float x, float y, float width, float height)
    {
        setPosition(x, y);
        setSize({ width, height });
        Setup();
    }
private:
    void Setup()
    {
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Yellow);
        setOutlineThickness(1.0f);
    }
};