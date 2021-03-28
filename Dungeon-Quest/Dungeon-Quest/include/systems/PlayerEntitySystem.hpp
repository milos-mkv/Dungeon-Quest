#pragma once

#include <systems/IEntitySystem.hpp>
#include <vector>
#include <Entity.hpp>
#include <components/AnimationComponent.hpp>
#include <Defines.h>
#include <Level.hpp>

struct PlayerEntitySystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit PlayerEntitySystem(const PTR<Level>& level);
    void Update(float delta) override;

private:
    void UpdatePlayerAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
};