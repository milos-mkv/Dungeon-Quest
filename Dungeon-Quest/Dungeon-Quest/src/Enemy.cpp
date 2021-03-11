#include <Enemy.h>
#include <Assets.h>
#include <Defines.h>
#include <Types.h>

Enemy::Enemy(EnemyType type, float x, float y) : type(type)
{
    state = Character::State::IDLE;
    setPosition({ x, y });

    setTexture(Assets::EnemyTextures[type][state][0]);
    collider.setPosition(x, y + ENEMY_COLLIDER_HEIGHT_OFFSET);
    collider.setSize({ (float) ENEMY_SIZES[type].x, (float)ENEMY_SIZES[type].y - ENEMY_COLLIDER_HEIGHT_OFFSET });
}

void Enemy::UpdateAnimation(float delta)
{
    timer += delta;
    if (timer >= 0.12f)
    {
        setTexture(Assets::EnemyTextures[type][state][index]);
        if (++index == 4)
            index = 0;
        timer = 0;
    }
}