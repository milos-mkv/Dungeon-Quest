#pragma once

#include <components/CharacterComponent.h>
#include <components/HeroComponent.hpp>
#include <components/DetectionComponent.hpp>
#include <components/RangeComponent.hpp>

/*!
 * Enemy Component class is used for creating any kind of enemies.
 */
struct EnemyComponent : public CharacterComponent
{
    RangeComponent      range;     // Attack range box of enemy.
    DetectionComponent  detection; // Detection box of enemy. (Detecting heroes)
    bool                chasing;   // Is chasing hero.

    EnemyComponent(CharacterType type, float x, float y);   // Paramterized constructor.
    void Update(float delta, HeroComponent* hero);          // Update state of enemy.
    void Draw() override;                                   // Draw enemy on screen.
};

