#pragma once

#include <SFML/Graphics.hpp>
#include "Types.h"
#include "Assets.h"
#include "Collision.hpp"

#define SPEED 100

struct Hero : public sf::Sprite
{
    HeroType     type;
    HeroState    state;
    CollisionBox box;
    sf::Vector2f speed;
    float timer = 0;
    int index = 0;
    
    Hero(HeroType type, float x, float y) : type(type), state(HeroState::IDLE)
    {
        setPosition({ x, y });
        setTexture(Assets::HeroTextures[type][state][0]);
        box.setPosition(x, y + HERO_HEIGHT_OFFSET);
        box.setSize({ HERO_WIDTH, HERO_HEIGHT - HERO_HEIGHT_OFFSET });
    }

    void ProcessInput(float delta)
    {
        state = HeroState::IDLE;
        speed = { 0, 0 };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            speed.x = -SPEED * delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            speed.x = SPEED * delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            speed.y = -SPEED * delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            speed.y = SPEED * delta;
        }
        if(speed.x || speed.y)
            state = HeroState::RUN;

        timer += delta;
        if (timer >= 0.12f)
        {
            setTexture(Assets::HeroTextures[type][state][index]);
            if (++index == 4)
                index = 0;
            timer = 0;
        }
    }

    void Update(float delta)
    {
        move(speed);
        box.setPosition(getPosition().x, getPosition().y + HERO_HEIGHT_OFFSET);

    }
};



/*
#include <SFML/Graphics.hpp>
#include <map>
#include "Defines.h"

static const std::string HEROES[HERO_TYPE_COUNT] = { "elf_m", "knight_m", "wizzard_m" };

#define HERO_MAX_LIFE       3
#define HERO_DEFAULT_SPEED  70

struct Hero : public sf::Sprite
{
    enum Type  { ELF, KNIGHT, WIZZARD };
    enum State { IDLE, RUN, HIT };
    
    Type  type;
    State state;

    float timer;
    int   index;
    float life;
    float speed;

    Hero(Type type)
        : type(type), state(State::IDLE), timer(0), index(0) 
    { 
        life  = HERO_MAX_LIFE;
        speed = HERO_DEFAULT_SPEED;
    }
    void SetState(State state);
    void Update(float delta);
private:
    void KeyboardInput(float delta);
};

struct HeroAssets
{
    static inline std::map<Hero::Type, sf::Texture[HERO_STATE_COUNT][SPRITE_ANIM_NUM]> textures;

    static void LoadHeroAssets();
    static void LoadTexturesForHero(const std::string& name, Hero::Type type);
};

struct HeroFactory
{
    static PTR<Hero> CreateHero(Hero::Type type, float x, float y);
};*/