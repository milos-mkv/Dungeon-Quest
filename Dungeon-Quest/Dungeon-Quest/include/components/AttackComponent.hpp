#pragma once

/*!
 * Attack Component class is used for defining entity capable of attacking.
*/
struct AttackComponent
{
    float attackSpeed;      // Attack speed.
    float attackSpeedTimer; // Attack cooldown. (When 0 means it is ready to attack)

    AttackComponent() = default;                                // Default constructor.
    AttackComponent(float attackSpeed, float attackSpeedTimer)  // Parametrized constructor.
        : attackSpeed(attackSpeed), attackSpeedTimer(attackSpeedTimer) { }

    /*!
     * Update attak speed timer and if needed reset it.
     */
    void UpdateAttackStatus(float delta)
    {
        if (attackSpeedTimer > 0.f && (attackSpeedTimer += delta) > attackSpeed)
            attackSpeedTimer = 0.f;
    }
};