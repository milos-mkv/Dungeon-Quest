#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

/*!
 * Detection Component class is used for creating detection boxes for enemy type characters. (Detect hero if nearby)
 */
struct DetectionComponent : public sf::RectangleShape
{
    DetectionComponent(); // Default constructor.
    DetectionComponent(float x, float y, float width, float height); // Parametrized constructor.
private:
    void Setup(); // Setup collider otiline color and size.
};