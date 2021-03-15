#pragma once

#include <SFML/Graphics.hpp>
#include <components/CharacterComponent.h>
#include <components/HeroComponent.hpp>
#include <components/DetectionComponent.hpp>
#include "Defines.h"

struct EnemyComponent : public CharacterComponent
{
    bool chasing = false;
    DetectionComponent detection;
    EnemyComponent(CharacterType type, float x, float y);
    void Update(float delta, HeroComponent* hero);
    void Draw() override;
};

