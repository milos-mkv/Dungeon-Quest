#pragma once

#include <systems/IEntitySystem.hpp>
#include <Level.hpp>
#include <components/AnimationComponent.hpp>

struct LevelItemSystem final : public IEntitySystem
{
    PTR<Level> level;
    explicit LevelItemSystem(const PTR<Level>& level);
    void Update(float delta) override;

private:
    void UpdateItemAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
    void UpdateCoinAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const;
};