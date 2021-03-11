#pragma once

#include <SFML/Graphics.hpp>

struct Camera : public sf::View
{
    Camera(float x, float y, float width, float height);
};
