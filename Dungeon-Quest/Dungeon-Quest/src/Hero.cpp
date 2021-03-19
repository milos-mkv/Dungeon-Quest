#include <components/HeroComponent.hpp>

#include <Defines.h>
#include <iostream>
#include <Assets.h>

static const float MaxHurtTime = 1.0f;

HeroComponent::HeroComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    life = 3;
}

void HeroComponent::ProcessInput(float delta)
{
    speed = { 0, 0 };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        speed.x = -HERO_SPEED * delta;
        FlipTexture(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        speed.x = HERO_SPEED * delta;
        FlipTexture(false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speed.y = -HERO_SPEED * delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        speed.y = HERO_SPEED * delta;
    }

    state = (speed.x || speed.y) ? CharacterState::RUN : CharacterState::IDLE;

    UpdateAnimation(delta);
}

void HeroComponent::Update(float delta)
{
    move(speed);
    sprite.move(speed);
}
