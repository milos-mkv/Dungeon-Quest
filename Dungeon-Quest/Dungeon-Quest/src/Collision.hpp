#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Defines.h"

struct CollisionBox : public sf::RectangleShape
{
    float x, y, width, height;

    CollisionBox()
    {
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Green);
        setOutlineThickness(1.0f);
    }
    CollisionBox(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) 
    { 
        setPosition({ x, y });
        setSize({ abs(width - x) + TILE_SIZE, abs(height - y) + TILE_SIZE });
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Green);
        setOutlineThickness(1.0f);
    }
};
