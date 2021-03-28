#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <components/Component.hpp>

#include <components/ColliderComponent.hpp>
#include <components/AttackComponent.hpp>
#include <components/ProjectileComponent.hpp>

#include <vector>

static const std::vector<std::string> CHARACTER_NAMES =
{
    "elf_m", "knight_m", "wizzard_m",  "ogre", "orc_shaman", "orc_warrior", "big_demon", "chort", "skelet", "big_zombie", "goblin", "imp", "masked_orc"
};

enum CharacterType 
{ 
    ELF, KNIGHT, WIZZARD, OGRE, ORC_SHAMAN, ORC_WARRIOR, BIG_DEMON, CHORT, SKELET, BIG_ZOMBIE, GOBLIN, IMP, MASKED_ORC 
};
enum CharacterState 
{ 
    IDLE, RUN, HIT 
}; 
enum CharacterAttackType 
{ 
    MELEE, RANGED 
};

struct CharacterComponent : public IComponent
{
    CharacterAttackType attackType;
    CharacterType       type;
    CharacterState      state = CharacterState::IDLE;
    sf::Vector2f        speed = { 0.0F, 0.0F };
    int                 life;

    explicit CharacterComponent(CharacterType type, CharacterAttackType attackType, int life)
        : type(type), attackType(attackType), life(life) { }
};

struct CharacterDefaultProperties
{
    sf::Vector2f        spriteSize;
    sf::Vector2f        colliderSize;
    CharacterAttackType attackType;
    float               moveSpeed;
    float               attackSpeed;
    ProjectileType      projectileType;
    float               range;
    int                 life;

    CharacterDefaultProperties() = default;
};

/*!
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+-----------------+--------------+    
 * | Character Type | Sprite Size | Collider Size | Character Attack Type | Movement Speed | Attack Speed | Projectile Type | Attack Range |
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+-----------------+--------------+
 */
static std::map<CharacterType, CharacterDefaultProperties> CharacterProperties =
{ 
    { CharacterType::ELF,           { { 16.0F, 28.0F }, { 14.0F, 18.0F }, CharacterAttackType::RANGED, 100, 0.01F, ProjectileType::ARROW,     1.0F, 3 } },
    { CharacterType::KNIGHT,        { { 16.0F, 28.0F }, { 14.0F, 18.0F }, CharacterAttackType::MELEE,  100, 0.01F, ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::WIZZARD,       { { 16.0F, 28.0F }, { 14.0F, 18.0F }, CharacterAttackType::RANGED, 100, 1.F,  ProjectileType::BLUE_FIRE, 1.0F, 3 } },
    { CharacterType::OGRE,          { { 32.0F, 32.0F }, { 20.0F, 25.0F }, CharacterAttackType::MELEE,  50,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::ORC_SHAMAN,    { { 16.0F, 20.0F }, { 12.0F, 16.0F }, CharacterAttackType::RANGED, 70,  0.01F, ProjectileType::RED_FIRE,  50.F, 3 } },
    { CharacterType::ORC_WARRIOR,   { { 16.0F, 20.0F }, { 12.0F, 16.0F }, CharacterAttackType::MELEE,  70,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::BIG_DEMON,     { { 31.0F, 35.0F }, { 25.0F, 25.0F }, CharacterAttackType::RANGED, 50,  1.0F,  ProjectileType::RED_FIRE,  70.F, 3 } },
    { CharacterType::CHORT,         { { 16.0F, 24.0F }, { 12.0F, 20.0F }, CharacterAttackType::RANGED, 50,  1.0F,  ProjectileType::RED_FIRE,  70.F, 3 } },
    { CharacterType::SKELET,        { { 16.0F, 16.0F }, { 12.0F, 12.0F }, CharacterAttackType::MELEE,  50,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::BIG_ZOMBIE,    { { 32.0F, 34.0F }, { 25.0F, 25.0F }, CharacterAttackType::MELEE,  50,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::GOBLIN,        { { 16.0F, 16.0F }, { 12.0F, 12.0F }, CharacterAttackType::MELEE,  50,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::IMP,           { { 16.0F, 16.0F }, { 12.0F, 12.0F }, CharacterAttackType::MELEE,  50,  1.0F,  ProjectileType::NONE,      1.0F, 3 } },
    { CharacterType::MASKED_ORC,    { { 16.0F, 20.0F }, { 12.0F, 16.0F }, CharacterAttackType::RANGED, 50,  0.01F, ProjectileType::ARROW,     50.F, 3 } },
};