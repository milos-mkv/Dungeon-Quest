#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

/*!
 * Collider Component class is used to specify collider box of character or non character object in game. 
 */
struct ColliderComponent : public sf::RectangleShape
{
    ColliderComponent(); // Default constructor.
    /*!
     * Parametrized constructor. (To be used only for setting tile based collider box, ex. Walls)
     */
    ColliderComponent(float x, float y, float width, float height); 
private:
    void Setup(); // Setup collider otiline color and size.
};
