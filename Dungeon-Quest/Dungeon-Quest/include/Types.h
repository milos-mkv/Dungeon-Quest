#pragma once

#include <map>
#include <SFML/System.hpp>

static const int HERO_TYPE_COUNT = 3;

enum HeroType 
{ 
    ELF, KNIGHT, WIZZARD 
};

static const std::string HERO_NAMES[HERO_TYPE_COUNT] = 
{ 
    "elf_m", "knight_m", "wizzard_m" 
};


static const int ENEMY_TYPE_COUNT = 3;

enum EnemyType
{
    OGRE, ORC_SHAMAN, ORC_WARRIOR
};

static const std::string ENEMY_NAMES[ENEMY_TYPE_COUNT] =
{
    "ogre", "orc_shaman", "orc_warrior"
};



static std::map<EnemyType, sf::Vector2i> ENEMY_SIZES =
{
    { EnemyType::OGRE,        { 30, 30 } },
    { EnemyType::ORC_SHAMAN,  { 16, 20 } },
    { EnemyType::ORC_WARRIOR, { 16, 20 } }
};