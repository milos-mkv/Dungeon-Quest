#pragma once

#include <systems/IEntitySystem.hpp>
#include <vector>
#include <Entity.hpp>
#include <components/AnimationComponent.hpp>
#include <Defines.h>
#include <Level.hpp>

struct ParticleEntitySystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit ParticleEntitySystem(const PTR<Level>& level);
    void Update(float delta) override;

private:
    bool UpdateParticleAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
};