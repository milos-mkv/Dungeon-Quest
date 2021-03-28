#include <systems/EnemyEntitySystem.hpp>

#include <components/CharacterComponent.h>
#include <components/SpriteComponent.hpp>
#include <components/AttackComponent.hpp>
#include <components/AnimationComponent.hpp>
#include <components/EnemyComponent.hpp>
#include <iostream>
#include <components/ColliderComponent.hpp>
#include <Assets.h>

static void FlipTexture(CharacterType type, sf::Sprite& sprite, bool flip);

EnemyEntitySystem::EnemyEntitySystem(const PTR<Level>& level)
    : level(level)
{
}

void EnemyEntitySystem::Update(float delta)
{
    for (auto iter = level->enemies.begin(); iter < level->enemies.end(); iter++)
    {
        auto characterComponent = (*iter)->GetComponent<CharacterComponent>();
        auto spriteComponent    = (*iter)->GetComponent<SpriteComponent>();
        auto attackComponent    = (*iter)->GetComponent<AttackComponent>();
        auto animationComponent = (*iter)->GetComponent<AnimationComponent>();
        auto colliderComponent  = (*iter)->GetComponent<ColliderComponent>();
        auto enemyComponent     = (*iter)->GetComponent<EnemyComponent>();
        
        sf::Vector2f dif = colliderComponent->collider.getPosition() - level->player->GetComponent<ColliderComponent>()->collider.getPosition();
        sf::Vector2f dir = normalize(dif);

        attackComponent->UpdateAttackStatus(delta);
        if (enemyComponent->chasing)
        {
            FlipTexture(characterComponent->type, spriteComponent->sprite, dif.x > 0);
            characterComponent->speed = { -dir.x * CharacterProperties[characterComponent->type].moveSpeed * delta , 
                                          -dir.y * CharacterProperties[characterComponent->type].moveSpeed * delta };
        }
        
        UpdateEnemyAnimation(animationComponent, delta);
        spriteComponent->sprite.setTexture(Assets::CharacterTextures[characterComponent->type][characterComponent->state][animationComponent->index]);
    }
}

void EnemyEntitySystem::UpdateEnemyAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 4;
        animationComponent->timer = 0;
    }
}

static void FlipTexture(CharacterType type, sf::Sprite& sprite, bool flip)
{
    if (flip)
        sprite.setTextureRect(sf::IntRect((int)CharacterProperties[type].spriteSize.x, 0, -(int)CharacterProperties[type].spriteSize.x, (int) CharacterProperties[type].spriteSize.y));
    else
        sprite.setTextureRect(sf::IntRect(0, 0, (int) CharacterProperties[type].spriteSize.x, (int) CharacterProperties[type].spriteSize.y));
}