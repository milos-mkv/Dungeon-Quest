#include <Hero.h>
#include <Defines.h>
#include <iostream>
#include <Assets.h>
#include <Character.h>

Hero::Hero(HeroType type, float x, float y) : type(type)
{
    state = Character::State::IDLE;
    setPosition({ x, y });
    setTexture(Assets::HeroTextures[type][state][0]);
    collider.setPosition(x, y + HERO_COLLIDER_HEIGHT_OFFSET);
    collider.setSize({ HERO_WIDTH, HERO_HEIGHT - HERO_COLLIDER_HEIGHT_OFFSET });
}

void Hero::ProcessInput(float delta)
{
    speed = { 0, 0 };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        speed.x = -HERO_SPEED * delta;
        setTextureRect(sf::IntRect(HERO_WIDTH, 0, -HERO_WIDTH, HERO_HEIGHT));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        speed.x = HERO_SPEED * delta;
        setTextureRect(sf::IntRect(0, 0, HERO_WIDTH, HERO_HEIGHT));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speed.y = -HERO_SPEED * delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        speed.y = HERO_SPEED * delta;
    }

    state = (speed.x || speed.y) ? Character::State::RUN : Character::State::IDLE;

    UpdateAnimation(delta);
}

void Hero::Update(float delta)
{
    move(speed);
    collider.setPosition(getPosition().x, getPosition().y + HERO_COLLIDER_HEIGHT_OFFSET);
}

void Hero::UpdateAnimation(float delta)
{
    timer += delta;
    if (timer >= 0.12f)
    {
        setTexture(Assets::HeroTextures[type][state][index]);
        if (++index == 4)
            index = 0;
        timer = 0;
    }
}