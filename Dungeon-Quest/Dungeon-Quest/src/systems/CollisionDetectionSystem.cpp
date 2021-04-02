#include <systems/CollisionDetectionSystem.hpp>
#include <components/ColliderComponent.hpp>
#include <components/CharacterComponent.h>
#include <components/EnemyComponent.hpp>
#include <components/DetectionComponent.hpp>
#include <components/CoinComponent.hpp>

#include <screens/GameplayScreen.h>
#include <iostream>
#include <EntityFactory.hpp>

static bool CheckCollisionX(const PTR<Entity>& e1, const sf::RectangleShape& r2);
static bool CheckCollisionY(const PTR<Entity>& e1, const sf::RectangleShape& r2);
static bool CheckCollision (const sf::RectangleShape& r1, const sf::RectangleShape& r2);

CollisionDetectionSystem::CollisionDetectionSystem(const PTR<Level>& level) 
    : level(level)
{
}

void CollisionDetectionSystem::Update(float delta)
{
    for (const auto& wall : level->walls)
    {
        auto wallCollider = wall->GetComponent<ColliderComponent>();

        if (CheckCollisionX(level->player, wallCollider->collider)) level->player->GetComponent<CharacterComponent>()->speed.x = 0;
        if (CheckCollisionY(level->player, wallCollider->collider)) level->player->GetComponent<CharacterComponent>()->speed.y = 0;

        for (const auto& enemy : level->enemies)
        {
            if (CheckCollisionX(enemy, wallCollider->collider)) enemy->GetComponent<CharacterComponent>()->speed.x = 0;
            if (CheckCollisionY(enemy, wallCollider->collider)) enemy->GetComponent<CharacterComponent>()->speed.y = 0;
        }

        for (auto iter = level->projectiles.begin(); iter < level->projectiles.end(); iter++)
        {
            if (CheckCollision((*iter)->GetComponent<ColliderComponent>()->collider, wallCollider->collider))
            {
                level->particles.push_back(EntityFactory::CreateParticle(ParticleType::PUF, (*iter)->GetComponent<ColliderComponent>()->collider.getPosition()));
                level->projectiles.erase(iter);
            }
        }
    }

    for (const auto& item : level->items)
    {
        auto wallCollider   = item->GetComponent<ColliderComponent>();
        auto chestComponent = item->GetComponent<ChestComponent>();
        auto coinComponent  = item->GetComponent<CoinComponent>();


        

        if (CheckCollisionX(level->player, wallCollider->collider))
        {
            level->player->GetComponent<CharacterComponent>()->speed.x = 0;
            if(chestComponent)
            {
                chestComponent->opened = true;
            }
        }
        if (CheckCollisionY(level->player, wallCollider->collider))
        {
            level->player->GetComponent<CharacterComponent>()->speed.y = 0;
            if (chestComponent)
                chestComponent->opened = true;
        }
        for (const auto& enemy : level->enemies)
        {
            if (CheckCollisionX(enemy, wallCollider->collider)) enemy->GetComponent<CharacterComponent>()->speed.x = 0;
            if (CheckCollisionY(enemy, wallCollider->collider)) enemy->GetComponent<CharacterComponent>()->speed.y = 0;
        }

        for (auto iter = level->projectiles.begin(); iter < level->projectiles.end(); iter++)
        {
            if (CheckCollision((*iter)->GetComponent<ColliderComponent>()->collider, wallCollider->collider))
            {
                level->particles.push_back(EntityFactory::CreateParticle(ParticleType::PUF, (*iter)->GetComponent<ColliderComponent>()->collider.getPosition()));
                level->projectiles.erase(iter);
            }
        }


    }
    for (const auto& enemy : level->enemies)
    {
        auto characterComponent = enemy->GetComponent<CharacterComponent>();
        auto enemyComponent     = enemy->GetComponent<EnemyComponent>();
        auto detectionComponent = enemy->GetComponent<DetectionComponent>();
        auto rangeComponent     = enemy->GetComponent<RangeComponent>();
        auto attackComponent    = enemy->GetComponent<AttackComponent>();
        auto colliderComponent  = enemy->GetComponent<ColliderComponent>();

        if (!enemyComponent->chasing && 
           (CheckCollisionX(level->player, detectionComponent->detection) || CheckCollisionY(level->player, detectionComponent->detection)))
        {
            enemyComponent->chasing   = true;
            characterComponent->state = CharacterState::RUN;
        }

        if(enemyComponent->chasing)
            characterComponent->state = CharacterState::RUN;

        if (CheckCollisionX(level->player, rangeComponent->range) || CheckCollisionY(level->player, rangeComponent->range))
        {
            characterComponent->speed = { 0, 0 };
            characterComponent->state = CharacterState::IDLE;

            if (attackComponent->timer == 0.F && characterComponent->attackType == CharacterAttackType::RANGED)
            {
                attackComponent->timer += delta;
                sf::Vector2f to = { level->player->GetComponent<ColliderComponent>()->GetCenter().x + RandFloat(-15, 15), 
                                    level->player->GetComponent<ColliderComponent>()->GetCenter().y + RandFloat(-15, 15) };
                level->projectiles.push_back(EntityFactory::CreateProjectile(CharacterProperties[characterComponent->type].projectileType, 
                                                                             colliderComponent->GetCenter(), to, false));
            }
            else if (characterComponent->attackType == CharacterAttackType::MELEE && attackComponent->timer == 0.F)
            {
                attackComponent->timer += delta;
                if ((--level->player->GetComponent<CharacterComponent>()->life) < 0)
                {
                    level->player->GetComponent<CharacterComponent>()->life = 0;
                }
            }
        }
    }


    for (auto iter = level->projectiles.begin(); iter < level->projectiles.end(); iter++)
    {
        if ((*iter)->GetComponent<PlayerComponent>())
        {
            for (auto enemy = level->enemies.begin(); enemy < level->enemies.end(); enemy++)
            {
                if (CheckCollision((*enemy)->GetComponent<ColliderComponent>()->collider, (*iter)->GetComponent<ColliderComponent>()->collider))
                {
                    level->projectiles.erase(iter);
                    (*enemy)->GetComponent<EnemyComponent>()->chasing = true;
                    if (--(*enemy)->GetComponent<CharacterComponent>()->life == 0)
                    {
                        level->particles.push_back(EntityFactory::CreateParticle(ParticleType::DEAD, (*enemy)->GetComponent<ColliderComponent>()->collider.getPosition()));
                        level->enemies.erase(enemy);
                    }
                    break;
                }
            }
        }
        else
        {
            if (CheckCollision(level->player->GetComponent<ColliderComponent>()->collider, (*iter)->GetComponent<ColliderComponent>()->collider))
            {
                level->projectiles.erase(iter);
                if ((--level->player->GetComponent<CharacterComponent>()->life) < 0)
                    level->player->GetComponent<CharacterComponent>()->life = 0;
                continue;
            }
        }
    }

    auto playerChracterComponent = level->player->GetComponent<CharacterComponent>();

    if ((bool)playerChracterComponent->speed.x && (bool)playerChracterComponent->speed.y)
    {
        playerChracterComponent->speed = { playerChracterComponent->speed.x / 1.2F, playerChracterComponent->speed.y / 1.2F };
    }
}

static bool CheckCollisionX(const PTR<Entity>& e1, const sf::RectangleShape& r2)
{
    auto c1 = e1->GetComponent<ColliderComponent>();
    auto ch = e1->GetComponent<CharacterComponent>();

    return (c1->collider.getPosition().x + ch->speed.x + c1->collider.getSize().x > r2.getPosition().x && r2.getPosition().x + r2.getSize().x >= c1->collider.getPosition().x + ch->speed.x)
        && (c1->collider.getPosition().y + c1->collider.getSize().y >= r2.getPosition().y && r2.getPosition().y + r2.getSize().y >= c1->collider.getPosition().y);
}

static bool CheckCollisionY(const PTR<Entity>& e1, const sf::RectangleShape& r2)
{
    auto c1 = e1->GetComponent<ColliderComponent>();
    auto ch = e1->GetComponent<CharacterComponent>();

    return (c1->collider.getPosition().x + c1->collider.getSize().x >= r2.getPosition().x && r2.getPosition().x + r2.getSize().x >= c1->collider.getPosition().x)
        && (c1->collider.getPosition().y + ch->speed.y + c1->collider.getSize().y >= r2.getPosition().y && r2.getPosition().y + r2.getSize().y >= c1->collider.getPosition().y + ch->speed.y);
}

static bool CheckCollision(const sf::RectangleShape& r1, const sf::RectangleShape& r2)
{
    return (r1.getPosition().x + r1.getSize().x >= r2.getPosition().x && r2.getPosition().x + r2.getSize().x >= r1.getPosition().x)
        && (r1.getPosition().y + r1.getSize().y >= r2.getPosition().y && r2.getPosition().y + r2.getSize().y >= r1.getPosition().y);
}
