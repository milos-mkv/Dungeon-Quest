#pragma once

struct Stats
{
    float speed;
    float life;
    float damage;

    Stats() = default;
    Stats(float speed, float life, float damage) : speed(speed), life(life), damage(damage) { }
};

struct Animation
{
    float timer;
    int   index;

    virtual void Update(float delta) = 0;
};

struct Hero : public sf::Sprite, public Stats, public Animation
{
    enum Type  { ELF, KNIGHT, WIZZARD };
    enum State { IDLE, RUN };

    Type  type;
    State state;

    Hero(Type type, Stats stats)
        : type(type), state(IDLE), Stats(stats.speed, stats.life, stats.damage) { }
    void Update(float delta) override;
};


void Hero::Update(float delta)
{
    timer += delta;
    if (timer >= 0.1f)
    {
      //  setTexture(EnemyAssets::textures[type][state][index]);
        if (++index == SPRITE_ANIM_NUM)
            index = 0;
        timer = 0;
    }
}