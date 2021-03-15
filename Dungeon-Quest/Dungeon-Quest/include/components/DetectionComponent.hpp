#pragma once

#include <SFML/Graphics.hpp>

struct DetectionComponent : public sf::RectangleShape
{
    DetectionComponent()
    {
        Setup();
    }
    DetectionComponent(float x, float y, float width, float height)
    {
        setPosition(x, y);
        setSize({ width, height });
        Setup();
    }
private:
    void Setup()
    {
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Red);
        setOutlineThickness(1.0f);
    }

};