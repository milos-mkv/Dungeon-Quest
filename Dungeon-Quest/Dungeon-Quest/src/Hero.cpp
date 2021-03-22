#include <components/HeroComponent.hpp>

#include <Defines.h>
#include <iostream>
#include <Assets.h>


HeroComponent::HeroComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    attackSpeed      = CharacterProperties[type].attackSpeed;
    attackSpeedTimer = 0.0f;
}

void HeroComponent::ProcessInput(float delta)
{
    speed = { 0, 0 };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        speed.x = -CharacterProperties[type].moveSpeed * delta;
        FlipTexture(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        speed.x = CharacterProperties[type].moveSpeed * delta;
        FlipTexture(false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speed.y = -CharacterProperties[type].moveSpeed * delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        speed.y = CharacterProperties[type].moveSpeed * delta;
    }

    state = (speed.x || speed.y) ? CharacterState::RUN : CharacterState::IDLE;
    UpdateAttackStatus(delta);

    UpdateAnimation(delta);
}

void HeroComponent::Update(float delta)
{
    move(speed);
    sprite.move(speed);
}
