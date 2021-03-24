#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <Defines.h>
#include <components/AnimationComponent.h>


enum ProjectileType { RED_FIRE, ARROW, BLUE_FIRE, NONE };

struct ProjectileComponent : public sf::RectangleShape, public AnimationComponent
{
    ProjectileType type;
    sf::Vector2f targetPosition;
    bool done;

    ProjectileComponent(ProjectileType type, const sf::Vector2f& position, const sf::Vector2f& targetPosition);
    void Update(float delta);
    void UpdateAnimation(float delta) override;
};