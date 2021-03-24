#include <components/ParticleComponent.hpp>

#include <Assets.h>

ParticleComponent::ParticleComponent(ParticleType type, float x, float y)
{
    this->type = type;
    done = false;
    sprite.setPosition(x, y);
    sprite.setTexture(Assets::ParticleTextures[type][0]);
}

void ParticleComponent::UpdateAnimation(float delta)
{
    if ((timer += delta) >= 0.07f)
    {
        sprite.setTexture(Assets::ParticleTextures[type][index]);
        index = (index + 1) % 4;
        timer = 0;
        if (index == 0) done = true;
    }
}