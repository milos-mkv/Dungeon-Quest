#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <Defines.h>
#include <components/AnimationComponent.h>

constexpr auto PROJECTILE_SPEED          =  150.f;
constexpr auto PROJECTILE_EXTRA_DISTANCE = -150.f;

enum ProjectileType { NONE, FIRE, ARROW };

struct ProjectileComponent : public sf::RectangleShape, public AnimationComponent
{
    ProjectileType type;
    sf::Vector2f targetPosition;
    bool done;

    ProjectileComponent(ProjectileType type, const sf::Vector2f& position, const sf::Vector2f& targetPosition);
    void Update(float delta);
    void UpdateAnimation(float delta) override;
};