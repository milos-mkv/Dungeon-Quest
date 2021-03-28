#pragma once

#include <components/Component.hpp>

enum ParticleType { PUF, BROKEN_ARROW };

struct ParticleComponent : public IComponent
{
    ParticleType type;
    bool         done = false;

    ParticleComponent(ParticleType type) : type(type) { }
};