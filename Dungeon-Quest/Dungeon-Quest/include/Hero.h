#pragma once

#include <SFML/Graphics.hpp>
#include "Types.h"
#include "Collision.hpp"
#include "Animation.h"
#include <Character.h>

struct Hero : public sf::Sprite, public Animation, public Character
{
    HeroType     type;

    Hero(HeroType type, float x, float y);

    void ProcessInput(float delta);
    void Update(float delta);
    void UpdateAnimation(float delta) override;
};
