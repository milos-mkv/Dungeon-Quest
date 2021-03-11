#pragma once

#include <SFML/System.hpp>
#include "Collision.hpp"

struct Character
{
    enum State { IDLE, RUN, HIT };

    State        state;
    CollisionBox collider;
    sf::Vector2f speed;

    Character() = default;
};