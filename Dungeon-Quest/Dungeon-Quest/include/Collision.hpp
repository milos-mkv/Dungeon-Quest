#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct CollisionBox : public sf::RectangleShape
{
    CollisionBox();
    CollisionBox(float x, float y, float width, float height);
private:
    void Setup();
};
