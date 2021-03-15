#pragma once

#include <components/CharacterComponent.h>

struct HeroComponent : public CharacterComponent
{
    HeroComponent(CharacterType type, float x, float y);

    void ProcessInput(float delta);
    void Update(float delta);
};
