#include <systems/ProjectileEntitySystem.hpp>

#include <components/AnimationComponent.hpp>
#include <components/ProjectileComponent.hpp>
#include <components/SpriteComponent.hpp>
#include <components/ColliderComponent.hpp>
#include <Game.h>

constexpr auto PROJECTILE_SPEED = -150.F;

ProjectileEntitySystem::ProjectileEntitySystem(const PTR<Level>& level)
    : level(level)
{
}

void ProjectileEntitySystem::Update(float delta)
{
    for (auto iter = level->projectiles.begin(); iter != level->projectiles.end(); iter++)
    {
        auto animationComponent  = (*iter)->GetComponent<AnimationComponent>();
        auto spriteComponent     = (*iter)->GetComponent<SpriteComponent>();
        auto colliderComponent   = (*iter)->GetComponent<ColliderComponent>();
        auto projectileComponent = (*iter)->GetComponent<ProjectileComponent>();
    
        UpdateProjectileAnimation(animationComponent, delta);

        sf::Vector2f diff = spriteComponent->sprite.getPosition() - projectileComponent->target;
        sf::Vector2f dir  = normalize(diff);


        if (std::sqrt(diff.x * diff.x + diff.y * diff.y) > 1.0F)
        {
            spriteComponent->sprite.move({ -dir.x * PROJECTILE_SPEED * delta, -dir.y * PROJECTILE_SPEED * delta });
            colliderComponent->collider.move({ -dir.x * PROJECTILE_SPEED * delta, -dir.y * PROJECTILE_SPEED * delta });
        }
        
        else
            projectileComponent->done = true;

        if (projectileComponent->done)
            level->projectiles.erase(iter);
    }
}

void ProjectileEntitySystem::UpdateProjectileAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 4;
        animationComponent->timer = 0;
    }
}