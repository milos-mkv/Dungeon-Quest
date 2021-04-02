#include <systems/LevelItemsSystem.hpp>
#include <Assets.h>
#include <components/SpriteComponent.hpp>
#include <components/ChestComponent.hpp>
#include <components/CoinComponent.hpp>
#include <iostream>
LevelItemSystem::LevelItemSystem(const PTR<Level>& level)
    : level(level)
{
}

void LevelItemSystem::Update(float delta)
{
    for (auto iter = level->items.begin(); iter < level->items.end(); iter++)
    {
        auto animationComponent = (*iter)->GetComponent<AnimationComponent>();
        auto chestComponent     = (*iter)->GetComponent<ChestComponent>();
        auto spriteComponent    = (*iter)->GetComponent<SpriteComponent>();
        auto coinComponent      = (*iter)->GetComponent<CoinComponent>();
        auto colliderComponent  = (*iter)->GetComponent<ColliderComponent>();

        if(chestComponent != nullptr && chestComponent->opened)
        {
            UpdateItemAnimation(animationComponent, delta);
            spriteComponent->sprite.setTexture(Assets::ChestTextures[chestComponent->type][animationComponent->index]);
        }
        else if (coinComponent != nullptr)
        {
            sf::Vector2f diff = colliderComponent->collider.getPosition() - coinComponent->target;
            sf::Vector2f dir = normalize(diff);

            if (std::sqrt(diff.x * diff.x + diff.y * diff.y) > 1.0F)
            {
                spriteComponent->sprite.move({ -dir.x * 50 * delta, -dir.y * 50 * delta });
                colliderComponent->collider.move({ -dir.x * 50 * delta, -dir.y * 50 * delta });
            }
            UpdateCoinAnimation(animationComponent, delta);
            spriteComponent->sprite.setTexture(Assets::CoinTextures[animationComponent->index]);
        }
    }
}

void LevelItemSystem::UpdateItemAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if (animationComponent->done)
        return;
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 3;
        animationComponent->timer = 0;
        if (animationComponent->index == 0)
        {
            animationComponent->index = 2;
            animationComponent->done = true;
        }
    }
}


void LevelItemSystem::UpdateCoinAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 3;
        animationComponent->timer = 0;
    }
}

