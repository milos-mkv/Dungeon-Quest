#include <systems/ParticleEntitySystem.hpp>
#include <Game.h>

#include <components/AnimationComponent.hpp>
#include <components/SpriteComponent.hpp>
#include <Assets.h>
#include <components/ParticleComponent.hpp>

ParticleEntitySystem::ParticleEntitySystem(const PTR<Level>& level)
    : level(level)
{
}

void ParticleEntitySystem::Update(float delta)
{
    for (auto iter = level->particles.begin(); iter < level->particles.end(); iter++)
    {
        auto animationComponent = (*iter)->GetComponent<AnimationComponent>();
        auto spriteComponent    = (*iter)->GetComponent<SpriteComponent>();
        auto particleComponent  = (*iter)->GetComponent<ParticleComponent>();

        particleComponent->done = UpdateParticleAnimation(animationComponent, delta);
        spriteComponent->sprite.setTexture(Assets::ParticleTextures[particleComponent->type][animationComponent->index]);
        
        if (particleComponent->done)
            level->particles.erase(iter);
    }
}

bool ParticleEntitySystem::UpdateParticleAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 4;
        animationComponent->timer = 0;

        if (animationComponent->index == 0)
            return true;
    }
    return false;
}