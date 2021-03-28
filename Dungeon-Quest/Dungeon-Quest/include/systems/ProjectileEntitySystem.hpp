#pragma once

#include <systems/IEntitySystem.hpp>
#include <vector>
#include <components/AnimationComponent.hpp>
#include <Entity.hpp>
#include <Defines.h>
#include <Level.hpp>

struct ProjectileEntitySystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit ProjectileEntitySystem(const PTR<Level>& level);
    void Update(float delta) override;
private:
    void UpdateProjectileAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
};