#pragma once

struct AttackComponent
{
    float attackSpeed;
    float attackSpeedTimer;

    AttackComponent() = default;
    AttackComponent(float attackSpeed, float attackSpeedTimer) 
        : attackSpeed(attackSpeed), attackSpeedTimer(attackSpeedTimer) { }

    void UpdateAttackStatus(float delta)
    {
        if (attackSpeedTimer > 0.f)
        {
            if ((attackSpeedTimer += delta) > attackSpeed)
                attackSpeedTimer = 0.f;
        }
    }
};