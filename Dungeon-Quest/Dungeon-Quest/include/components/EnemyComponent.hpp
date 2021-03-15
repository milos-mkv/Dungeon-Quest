#pragma once

#include <SFML/Graphics.hpp>
#include <components/CharacterComponent.h>
#include <components/HeroComponent.hpp>
#include "Defines.h"

struct EnemyComponent : public CharacterComponent
{
    EnemyComponent(CharacterType type, float x, float y);
    void Update(float delta, HeroComponent* hero);
};

