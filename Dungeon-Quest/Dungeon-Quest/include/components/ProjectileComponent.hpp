#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <Defines.h>
#include <components/AnimationComponent.hpp>


enum ProjectileType { RED_FIRE, ARROW, BLUE_FIRE, NONE };

struct ProjectileComponent : public IComponent 
{
    ProjectileType  type;
    sf::Vector2f    target;
    bool            done = false;

    ProjectileComponent(ProjectileType type, const sf::Vector2f& target)
        : type(type), target(target) { }
};

