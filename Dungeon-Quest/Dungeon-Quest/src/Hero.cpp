#include <components/HeroComponent.hpp>

#include <Defines.h>
#include <iostream>
#include <Assets.h>

constexpr int HERO_MAX_LIFE = 60;    // Hero max life points. Half heart is 1 point. Full 3 hearts = 6 points;

HeroComponent::HeroComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    life = HERO_MAX_LIFE;
}

void HeroComponent::ProcessInput(float delta)
{
    speed = { 0, 0 };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        speed.x = -CharacterProps[type].moveSpeed * delta;
        FlipTexture(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        speed.x = CharacterProps[type].moveSpeed * delta;
        FlipTexture(false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speed.y = -CharacterProps[type].moveSpeed * delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        speed.y = CharacterProps[type].moveSpeed * delta;
    }

    state = (speed.x || speed.y) ? CharacterState::RUN : CharacterState::IDLE;

    UpdateAnimation(delta);
}

void HeroComponent::Update(float delta)
{
    move(speed);
    sprite.move(speed);
}
