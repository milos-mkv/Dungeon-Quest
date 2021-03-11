#pragma once

#include <SFML/Graphics.hpp>
#include "Types.h"
#include "Collision.hpp"
#include "Animation.h"
#include "Character.h"

struct Enemy : public sf::Sprite, public Animation, public Character
{
    EnemyType    type;
    Enemy(EnemyType type, float x, float y);
    void UpdateAnimation(float delta) override;
};

