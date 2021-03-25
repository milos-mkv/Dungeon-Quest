#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

struct ColliderComponent : public sf::RectangleShape
{
    ColliderComponent();
    ColliderComponent(float x, float y, float width, float height); 
private:
    void Setup();
};
