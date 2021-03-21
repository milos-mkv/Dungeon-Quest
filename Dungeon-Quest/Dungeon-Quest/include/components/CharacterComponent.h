#pragma once

#include <SFML/System.hpp>

#include <components/ColliderComponent.hpp>
#include <components/AnimationComponent.h>
#include <components/AttackComponent.hpp>

static const int CHARACTER_TYPE_COUNT = 13;

static const std::string CHARACTER_NAMES[CHARACTER_TYPE_COUNT] =
{
    "elf_m", "knight_m", "wizzard_m",  "ogre", "orc_shaman", "orc_warrior", "big_demon", "chort", "skelet", "big_zombie", "goblin", "imp",
    "masked_orc"
};

enum CharacterType       { ELF, KNIGHT, WIZZARD, OGRE, ORC_SHAMAN, ORC_WARRIOR, BIG_DEMON, CHORT, SKELET, BIG_ZOMBIE, GOBLIN, IMP, MASKED_ORC };
enum CharacterState      { IDLE, RUN, HIT };
enum CharacterAttackType { MELEE, RANGED };

struct CharacterComponent : public AnimationComponent, public ColliderComponent, public AttackComponent
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

    sf::Vector2f GetCenter() 
    {
        return  getPosition() + getSize() / 2.f;
    }
};


struct CharacterProperties
{
    sf::Vector2f        spriteSize;
    sf::Vector2f        colliderSize;
    CharacterAttackType attackType;
    float               moveSpeed;
    float               attackSpeed;
    float               range;

    CharacterProperties() = default;
};

/*!
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+--------------+    
 * | Character Type | Sprite Size | Collider Size | Character Attack Type | Movement Speed | Attack Speed | Attack Range |
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+--------------+
*/
static std::map<CharacterType, CharacterProperties> CharacterProps =
{ 
    { CharacterType::ELF,           { { 16, 28 }, { 14, 18 }, CharacterAttackType::RANGED, 100, 1, 1  } },
    { CharacterType::KNIGHT,        { { 16, 28 }, { 14, 18 }, CharacterAttackType::MELEE,  100, 1, 1  } },
    { CharacterType::WIZZARD,       { { 16, 28 }, { 14, 18 }, CharacterAttackType::RANGED, 100, 1, 1  } },
    { CharacterType::OGRE,          { { 32, 32 }, { 20, 25 }, CharacterAttackType::MELEE,  50, 1, 1  } },
    { CharacterType::ORC_SHAMAN,    { { 16, 20 }, { 12, 16 }, CharacterAttackType::RANGED, 70, 1, 50 } },
    { CharacterType::ORC_WARRIOR,   { { 16, 20 }, { 12, 16 }, CharacterAttackType::MELEE,  70, 1, 1  } },
    { CharacterType::BIG_DEMON,     { { 31, 35 }, { 25, 25 }, CharacterAttackType::RANGED, 50, 0.01, 70  } },
    { CharacterType::CHORT,         { { 16, 24 }, { 12, 20 }, CharacterAttackType::RANGED, 50, 0.01, 70  } },
    { CharacterType::SKELET,        { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50, 1, 1  } },
    { CharacterType::BIG_ZOMBIE,    { { 32, 34 }, { 25, 25 }, CharacterAttackType::MELEE,  50, 1, 1  } },
    { CharacterType::GOBLIN,        { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50, 1, 1  } },
    { CharacterType::IMP,           { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50, 1, 1  } },
    { CharacterType::MASKED_ORC,    { { 16, 20 }, { 12, 16 }, CharacterAttackType::MELEE,  50, 1, 1  } },
};