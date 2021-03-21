#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

/*!
 * Range Component class is used for createing attack range boxes of enemies. 
 */
struct RangeComponent : public sf::RectangleShape
{
    RangeComponent(); // Default constructor.
    RangeComponent(float x, float y, float width, float height); // Parametrized constructor.
private:
    void Setup(); // Setup collider otiline color and size.
};