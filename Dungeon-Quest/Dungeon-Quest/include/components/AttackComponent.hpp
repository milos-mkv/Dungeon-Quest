#pragma once

#include <components/Component.hpp>

struct AttackComponent : public IComponent
{
    float speed;
    float timer = 0.0F;

    explicit AttackComponent(float speed) : speed(speed) { }

    void UpdateAttackStatus(float delta)
    {
        if (timer > 0.0F && (timer += delta) > speed)
            timer = 0.0F;
    }
};