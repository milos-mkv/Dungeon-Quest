#pragma once

#include <components/Component.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

struct DetectionComponent : public IComponent
{
    sf::RectangleShape detection;

    DetectionComponent()
    {
        Setup();
    }
    DetectionComponent(float x, float y, float width, float height)
    {
        detection.setPosition(x, y);
        detection.setSize({ width, height });
        Setup();
    }
private:
    void Setup()
    {
        detection.setFillColor(sf::Color::Transparent);
        detection.setOutlineColor(sf::Color::Red);
        detection.setOutlineThickness(1.0F);
    }
};