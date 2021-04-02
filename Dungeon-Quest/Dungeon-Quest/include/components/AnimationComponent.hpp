#pragma once

#include <components/Component.hpp>

constexpr int MAX_ANIMATION_SPRITES = 4;

struct AnimationComponent : public IComponent
{
    float timer       = 0.0F;
    int   index       = 0;
    float changeTimer = 0.1F;
    bool  done        = false;
    AnimationComponent(float timer, int index, float changeTimer)
        : timer(timer), index(index), changeTimer(changeTimer) { }
    AnimationComponent() = default;
};
