#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <Defines.h>
#include <Assets.h>
#include <components/AnimationComponent.h>

constexpr auto PROJECTILE_SPEED          =  150.f;
constexpr auto PROJECTILE_EXTRA_DISTANCE = -150.f;

enum ProjectileType { FIRE, ARROW };

struct ProjectileComponent : public sf::RectangleShape, public AnimationComponent
{
    sf::Vector2f targetPosition;
    bool done;

    ProjectileComponent(const sf::Vector2f& position, const sf::Vector2f& targetPosition)
        : targetPosition(targetPosition + normalize(position - targetPosition) * PROJECTILE_EXTRA_DISTANCE), done(false)
    {
        setPosition(position);
        setSize({ 5.f, 5.f });
#ifdef DEBUG_MODE
        setOutlineColor(sf::Color::Blue);
        setOutlineThickness(1.0f);
#endif
        setTexture(&Assets::FireTextures[0]);

        sf::Vector2f diff2 = position - targetPosition;
        rotate(atan2(diff2.y, diff2.x) * (180 / 3.14));
    }

    void Update(float delta)
    {
        UpdateAnimation(delta);
        sf::Vector2f diff = getPosition() - targetPosition;
        sf::Vector2f dir  = normalize(diff);


        if (std::sqrt(diff.x * diff.x + diff.y * diff.y) > 1.0f)
            move({ -dir.x * PROJECTILE_SPEED * delta, -dir.y * PROJECTILE_SPEED * delta });
        else
            done = true;
    }

    void UpdateAnimation(float delta) override
    {
        if ((timer += delta) >= 0.12f)
        {
            setTexture(&Assets::FireTextures[index]);
            index = (index + 1) % 4;
            timer = 0;
        }
    }
};