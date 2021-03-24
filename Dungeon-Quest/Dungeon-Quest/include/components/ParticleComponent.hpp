#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <components/AnimationComponent.h>

enum ParticleType { PUF, BROKEN_ARROW };

struct ParticleComponent :public AnimationComponent
{
    sf::Sprite sprite;
    ParticleType type;
    bool done;

    ParticleComponent(ParticleType type, float x, float y);
    void UpdateAnimation(float delta);
};