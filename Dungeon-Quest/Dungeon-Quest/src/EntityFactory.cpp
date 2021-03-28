#include <EntityFactory.hpp>
#include <Defines.h>
#include <Entity.hpp>

#include <components/CharacterComponent.h>
#include <components/ParticleComponent.hpp>
#include <components/SpriteComponent.hpp>
#include <components/AnimationComponent.hpp>
#include <components/ProjectileComponent.hpp>
#include <components/PlayerComponent.hpp>
#include <components/AttackComponent.hpp>
#include <components/ColliderComponent.hpp>
#include <components/EnemyComponent.hpp>
#include <components/DetectionComponent.hpp>
#include <components/RangeComponent.hpp>

#include <Assets.h>

PTR<Entity> EntityFactory::CreateParticle(ParticleType type, const sf::Vector2f& position)
{
    auto entity             = CreatePTR<Entity>();
    auto spriteComponent    = CreatePTR<SpriteComponent>(Assets::ParticleTextures[type][0], position.x, position.y);
    auto particleComponent  = CreatePTR<ParticleComponent>(type);
    auto animationComponent = CreatePTR<AnimationComponent>(1, 0, 0.12F);

    entity->AddComponent<SpriteComponent>(spriteComponent);
    entity->AddComponent<ParticleComponent>(particleComponent);
    entity->AddComponent<AnimationComponent>(animationComponent);

    return entity;
}
PTR<Entity> EntityFactory::CreateProjectile(ProjectileType type, const sf::Vector2f& position, const sf::Vector2f& target, bool fromPlayer)
{
    auto entity              = CreatePTR<Entity>();
    auto spriteComponent     = CreatePTR<SpriteComponent>(Assets::ProjectileTextures[type][0], position.x, position.y);
    auto projectileComponent = CreatePTR<ProjectileComponent>(type, (position + normalize(position - target) * 150.F));
    auto animationComponent  = CreatePTR<AnimationComponent>();
    auto colliderComponent   = CreatePTR<ColliderComponent>(position, (sf::Vector2f)spriteComponent->sprite.getTexture()->getSize());

    spriteComponent->sprite.setOrigin({ 2.5F, 2.5F });
    sf::Vector2f diff = position - target;
    spriteComponent->sprite.setRotation(atan2(diff.y, diff.x) * (180.0F / 3.14F));

    entity->AddComponent<SpriteComponent>(spriteComponent);
    entity->AddComponent<ProjectileComponent>(projectileComponent);
    entity->AddComponent<AnimationComponent>(animationComponent);
    entity->AddComponent<ColliderComponent>(colliderComponent);

    if (fromPlayer) entity->AddComponent<PlayerComponent>(CreatePTR<PlayerComponent>());
    else            entity->AddComponent<EnemyComponent>(CreatePTR<EnemyComponent>());

    return entity;
}

PTR<Entity> EntityFactory::CreateWall(const sf::Vector2f& position, const sf::Vector2f& size)
{
    auto entity            = CreatePTR<Entity>();
    auto colliderComponent = CreatePTR<ColliderComponent>(position.x, position.y, size.x, size.y);

    entity->AddComponent<ColliderComponent>(colliderComponent);

    return entity;
}

PTR<Entity> EntityFactory::CreateHero(CharacterType type, const sf::Vector2f& position)
{
    sf::Vector2f diff = GetVectorDiff(CharacterProperties[type].colliderSize, CharacterProperties[type].spriteSize);

    auto entity             = CreatePTR<Entity>();
    auto spriteComponent    = CreatePTR<SpriteComponent>(Assets::CharacterTextures[type][CharacterState::IDLE][0], position.x - diff.x / 2, position.y - diff.y);
    auto playerComponent    = CreatePTR<PlayerComponent>();
    auto animationComponent = CreatePTR<AnimationComponent>();
    auto characterComponent = CreatePTR<CharacterComponent>(type, CharacterProperties[type].attackType, CharacterProperties[type].life);
    auto attackComponent    = CreatePTR<AttackComponent>(CharacterProperties[type].attackSpeed);
    auto colliderComponent  = CreatePTR<ColliderComponent>(position, CharacterProperties[type].colliderSize);

    entity->AddComponent<SpriteComponent>(spriteComponent);
    entity->AddComponent<PlayerComponent>(playerComponent);
    entity->AddComponent<AnimationComponent>(animationComponent);
    entity->AddComponent<CharacterComponent>(characterComponent);
    entity->AddComponent<AttackComponent>(attackComponent);
    entity->AddComponent<ColliderComponent>(colliderComponent);

    return entity;
}

PTR<Entity> EntityFactory::CreateEnemy(CharacterType type, const sf::Vector2f& position)
{
    sf::Vector2f diff = GetVectorDiff(CharacterProperties[type].colliderSize, CharacterProperties[type].spriteSize);

    auto entity             = CreatePTR<Entity>();
    auto spriteComponent    = CreatePTR<SpriteComponent>(Assets::CharacterTextures[type][CharacterState::IDLE][0], position.x - diff.x / 2, position.y - diff.y);
    auto enemyComponent     = CreatePTR<EnemyComponent>();
    auto animationComponent = CreatePTR<AnimationComponent>();
    auto characterComponent = CreatePTR<CharacterComponent>(type, CharacterProperties[type].attackType, CharacterProperties[type].life);
    auto attackComponent    = CreatePTR<AttackComponent>(CharacterProperties[type].attackSpeed);
    auto colliderComponent  = CreatePTR<ColliderComponent>(position, CharacterProperties[type].colliderSize);
    auto detectionComponent = CreatePTR<DetectionComponent>(position.x - ENEMY_DETECTION_SIZE, position.y - ENEMY_DETECTION_SIZE,
        colliderComponent->collider.getSize().x + ENEMY_DETECTION_SIZE * 2, colliderComponent->collider.getSize().y + ENEMY_DETECTION_SIZE * 2);
    auto rangeComponent     = CreatePTR<RangeComponent>(position.x - CharacterProperties[type].range, position.y - CharacterProperties[type].range,
        colliderComponent->collider.getSize().x + CharacterProperties[type].range * 2, colliderComponent->collider.getSize().y + CharacterProperties[type].range * 2);

    entity->AddComponent<SpriteComponent>(spriteComponent);
    entity->AddComponent<EnemyComponent>(enemyComponent);
    entity->AddComponent<AnimationComponent>(animationComponent);
    entity->AddComponent<CharacterComponent>(characterComponent);
    entity->AddComponent<AttackComponent>(attackComponent);
    entity->AddComponent<ColliderComponent>(colliderComponent);
    entity->AddComponent<DetectionComponent>(detectionComponent);
    entity->AddComponent<RangeComponent>(rangeComponent);

    return entity;
}