#pragma once

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

constexpr int ENEMY_DETECTION_SIZE = 70;

struct EntityFactory final
{
    static PTR<Entity> CreateParticle(ParticleType type, const sf::Vector2f& position);

    static PTR<Entity> CreateProjectile(ProjectileType type, const sf::Vector2f& position, const sf::Vector2f& target, bool fromPlayer);

    static PTR<Entity> CreateWall(const sf::Vector2f& position, const sf::Vector2f& size);

    static PTR<Entity> CreateHero(CharacterType type, const sf::Vector2f& position);

    static PTR<Entity> CreateEnemy(CharacterType type, const sf::Vector2f& position);
};