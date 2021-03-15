#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../Defines.h"

struct ColliderComponent : public sf::RectangleShape
{
    ColliderComponent()
    {
        Setup();
    }

    ColliderComponent(float x, float y, float width, float height)
    {
        setPosition({ x, y });
        setSize({ abs(width - x) + TILE_SIZE, abs(height - y) + TILE_SIZE });
        Setup();
    }
private:
    void Setup()
    {
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Green);
        setOutlineThickness(1.0f);
    }
};
