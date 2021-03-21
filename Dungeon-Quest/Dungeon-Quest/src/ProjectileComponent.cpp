#include <components/ProjectileComponent.hpp>

#include <Assets.h>

ProjectileComponent::ProjectileComponent(ProjectileType type, const sf::Vector2f& position, const sf::Vector2f& targetPosition)
    : type(type), targetPosition(targetPosition + normalize(position - targetPosition) * PROJECTILE_EXTRA_DISTANCE), done(false)
{
    setPosition(position);
    setSize({ 5.f, 5.f });
#ifdef DEBUG_MODE
    setOutlineColor(sf::Color::Blue);
    setOutlineThickness(1.0f);
#endif
    setTexture(&Assets::ProjectileTextures[type][0]);

    sf::Vector2f diff2 = position - targetPosition;
    rotate(atan2(diff2.y, diff2.x) * (180 / 3.14));
}

void ProjectileComponent::Update(float delta)
{
    UpdateAnimation(delta);
    sf::Vector2f diff = getPosition() - targetPosition;
    sf::Vector2f dir = normalize(diff);


    if (std::sqrt(diff.x * diff.x + diff.y * diff.y) > 1.0f)
        move({ -dir.x * PROJECTILE_SPEED * delta, -dir.y * PROJECTILE_SPEED * delta });
    else
        done = true;
}

void ProjectileComponent::UpdateAnimation(float delta)
{
    if ((timer += delta) >= 0.12f)
    {
        setTexture(&Assets::ProjectileTextures[type][index]);
        index = (index + 1) % 4;
        timer = 0;
    }
}
