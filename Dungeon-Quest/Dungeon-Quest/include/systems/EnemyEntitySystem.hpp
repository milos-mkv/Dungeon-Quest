#pragma once

#include <systems/IEntitySystem.hpp>
#include <vector>
#include <Entity.hpp>
#include <components/AnimationComponent.hpp>
#include <Defines.h>
#include <Level.hpp>

struct EnemyEntitySystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit EnemyEntitySystem(const PTR<Level>& level);
    void Update(float delta) override;

private:
    void UpdateEnemyAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
};