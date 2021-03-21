#pragma once

#include <components/CharacterComponent.h>

/*!
 * Hero Component class is used for creating heroes. 
 */
struct HeroComponent : public CharacterComponent
{
    HeroComponent(CharacterType type, float x, float y);
    void ProcessInput(float delta);  // Process hero input.
    void Update(float delta);        // Update state of hero.
};
