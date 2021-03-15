#pragma once

#include <SFML/System.hpp>

#include <components/ColliderComponent.hpp>
#include <components/AnimationComponent.h>

static const int CHARACTER_TYPE_COUNT = 7;

static const std::string CHARACTER_NAMES[CHARACTER_TYPE_COUNT] =
{
    "elf_m", "knight_m", "wizzard_m",  "ogre", "orc_shaman", "orc_warrior", "big_demon"
};

enum CharacterType       { ELF, KNIGHT, WIZZARD, OGRE, ORC_SHAMAN, ORC_WARRIOR, BIG_DEMON };
enum CharacterState      { IDLE, RUN, HIT };
enum CharacterAttackType { MELEE, RANGED };

struct CharacterComponent : public AnimationComponent, public ColliderComponent
{
    CharacterAttackType attackType;
    CharacterType       type;
    CharacterState      state;
    sf::Sprite          sprite;
    sf::Vector2f        speed;
    
    CharacterComponent(CharacterType type, float x, float y);
    void UpdateAnimation(float delta);
    virtual void Draw();
    void FlipTexture(bool flip);
};


static std::map<CharacterType, sf::Vector2f> CharacterSpriteSizes =
{
    { CharacterType::ELF,         { 16, 28 } },
    { CharacterType::KNIGHT,      { 16, 28 } },
    { CharacterType::WIZZARD,     { 16, 28 } },
    { CharacterType::OGRE,        { 32, 32 } },
    { CharacterType::ORC_SHAMAN,  { 16, 20 } },
    { CharacterType::ORC_WARRIOR, { 16, 20 } },
    { CharacterType::BIG_DEMON,   { 31, 35 } }
};

static std::map<CharacterType, sf::Vector2f> CharacterColliderSizes =
{
    { CharacterType::ELF,         { 16, 16 } },
    { CharacterType::KNIGHT,      { 16, 16 } },
    { CharacterType::WIZZARD,     { 16, 16 } },
    { CharacterType::OGRE,        { 20, 25 } },
    { CharacterType::ORC_SHAMAN,  { 12, 16 } },
    { CharacterType::ORC_WARRIOR, { 12, 16 } },
    { CharacterType::BIG_DEMON,   { 25, 25 } }
};

static std::map<CharacterType, CharacterAttackType> CharacterAttackTypes =
{
    { CharacterType::ELF,         CharacterAttackType::RANGED },
    { CharacterType::KNIGHT,      CharacterAttackType::MELEE  },
    { CharacterType::WIZZARD,     CharacterAttackType::RANGED },
    { CharacterType::OGRE,        CharacterAttackType::MELEE  },
    { CharacterType::ORC_SHAMAN,  CharacterAttackType::RANGED },
    { CharacterType::ORC_WARRIOR, CharacterAttackType::MELEE  },
    { CharacterType::BIG_DEMON,   CharacterAttackType::MELEE  }
};