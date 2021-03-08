#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Defines.h"

static const std::string HEROES[HERO_TYPE_COUNT] = { "elf_m", "knight_m", "wizzard_m" };

struct Hero : public sf::Sprite
{
    enum Type  { ELF, KNIGHT, WIZZARD };
    enum State { IDLE, RUN, HIT };
    
    Type  type;
    State state;

    Hero(Type type)
        : type(type), state(State::IDLE) { }
};

struct HeroAssets
{
    static inline std::map<Hero::Type, sf::Texture[HERO_STATE_COUNT][SPRITE_ANIM_NUM]> textures;

    static void LoadHeroAssets()
    {
        for (int i = 0; i < HERO_TYPE_COUNT; i++)
        {
            LoadTexturesForHero(HEROES[i], (Hero::Type)i);
        }
    }

    static void LoadTexturesForHero(const std::string& name, Hero::Type type)
    {
        for (int i = 0; i < SPRITE_ANIM_NUM; i++)
        {
            ASSERT(textures[type][Hero::State::IDLE][i].loadFromFile("assets/frames/" + name + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
            ASSERT(textures[type][Hero::State::RUN] [i].loadFromFile("assets/frames/" + name + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
        }
        ASSERT(textures[type][Hero::State::HIT][0].loadFromFile("assets/frames/" + name + "_hit_anim_f0.png"), "Failed to load texture!");
    }
};

struct HeroFactory
{
    static PTR<Hero> CreateHero(Hero::Type type, float x, float y)
    {
        PTR<Hero> hero = CreatePTR<Hero>(type);
        hero->setScale({ SCALE_FACTOR, SCALE_FACTOR });
        hero->setPosition({ x, y });
        return hero;
    }
};