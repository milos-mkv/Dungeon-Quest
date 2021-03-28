#pragma once

#include <systems/IEntitySystem.hpp>

#include <systems/EnemyEntitySystem.hpp>
#include <systems/PlayerEntitySystem.hpp>
#include <systems/ParticleEntitySystem.hpp>
#include <systems/ProjectileEntitySystem.hpp>

#include <Level.hpp>
#include <vector>
#include <Entity.hpp>
#include <components/AnimationComponent.hpp>
#include <Defines.h>

struct CollisionDetectionSystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit CollisionDetectionSystem(const PTR<Level>& level);
    void Update(float delta) override;
};