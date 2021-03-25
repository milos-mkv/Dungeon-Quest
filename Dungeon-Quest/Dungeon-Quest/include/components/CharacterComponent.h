#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <components/ColliderComponent.hpp>
#include <components/AnimationComponent.h>
#include <components/AttackComponent.hpp>
#include <components/ProjectileComponent.hpp>

constexpr int CHARACTER_TYPE_COUNT = 13;
static const std::string CHARACTER_NAMES[CHARACTER_TYPE_COUNT] =
{
    "elf_m", "knight_m", "wizzard_m",  "ogre", "orc_shaman", "orc_warrior", "big_demon", "chort", "skelet", "big_zombie", "goblin", "imp", "masked_orc"
};

enum CharacterType { ELF, KNIGHT, WIZZARD, OGRE, ORC_SHAMAN, ORC_WARRIOR, BIG_DEMON, CHORT, SKELET, BIG_ZOMBIE, GOBLIN, IMP, MASKED_ORC };
enum CharacterState { IDLE, RUN, HIT };     // Hit type does not apply to non hero characters.
enum CharacterAttackType { MELEE, RANGED };

struct CharacterComponent : public AnimationComponent, public ColliderComponent, public AttackComponent
{
    CharacterAttackType attackType;
    CharacterType       type;
    CharacterState      state;
    sf::Sprite          sprite;
    sf::Vector2f        speed;
    int                 life;

    CharacterComponent(CharacterType type, float x, float y);

    void UpdateAnimation(float delta) override;
    virtual void Draw();
    void FlipTexture(bool flip);
    sf::Vector2f GetCenter() const;
};

/*!
 * Character Properties is used to store in it all basic information about certain type of character.
 */
struct CharacterDefaultProperties
{
    sf::Vector2f        spriteSize;             // Size of character sprite. (Size of loaded texture)
    sf::Vector2f        colliderSize;           // Size of character collider box.
    CharacterAttackType attackType;             // Attack type of character.
    float               moveSpeed;              // Default movement speed of character.
    float               attackSpeed;            // Default attack speed of character.
    ProjectileType      projectileType;         // Projectile type of character.
    float               range;                  // Attack range of character.
    int                 life;                   // Max life points of character.

    CharacterDefaultProperties() = default;    // Default constructor.
};

/*!
 * By using this map you can get default properties of any character.
 *
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+-----------------+--------------+    
 * | Character Type | Sprite Size | Collider Size | Character Attack Type | Movement Speed | Attack Speed | Projectile Type | Attack Range |
 * +----------------+-------------+---------------+-----------------------+----------------+--------------+-----------------+--------------+
 */
static std::map<CharacterType, CharacterDefaultProperties> CharacterProperties =
{ 
    { CharacterType::ELF,           { { 16, 28 }, { 14, 18 }, CharacterAttackType::RANGED, 100, 0.01, ProjectileType::ARROW, 1,  3 } },
    { CharacterType::KNIGHT,        { { 16, 28 }, { 14, 18 }, CharacterAttackType::MELEE,  100, 0.01, ProjectileType::NONE,  1,  3 } },
    { CharacterType::WIZZARD,       { { 16, 28 }, { 14, 18 }, CharacterAttackType::RANGED, 100, 0.01, ProjectileType::BLUE_FIRE,  1,  3 } },
    { CharacterType::OGRE,          { { 32, 32 }, { 20, 25 }, CharacterAttackType::MELEE,  50,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::ORC_SHAMAN,    { { 16, 20 }, { 12, 16 }, CharacterAttackType::RANGED, 70,  0.01, ProjectileType::RED_FIRE,  50, 3 } },
    { CharacterType::ORC_WARRIOR,   { { 16, 20 }, { 12, 16 }, CharacterAttackType::MELEE,  70,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::BIG_DEMON,     { { 31, 35 }, { 25, 25 }, CharacterAttackType::RANGED, 50,  1, ProjectileType::RED_FIRE,  70, 3 } },
    { CharacterType::CHORT,         { { 16, 24 }, { 12, 20 }, CharacterAttackType::RANGED, 50,  1, ProjectileType::RED_FIRE,  70, 3 } },
    { CharacterType::SKELET,        { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::BIG_ZOMBIE,    { { 32, 34 }, { 25, 25 }, CharacterAttackType::MELEE,  50,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::GOBLIN,        { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::IMP,           { { 16, 16 }, { 12, 12 }, CharacterAttackType::MELEE,  50,  1, ProjectileType::NONE,  1,  3 } },
    { CharacterType::MASKED_ORC,    { { 16, 20 }, { 12, 16 }, CharacterAttackType::RANGED, 50,  0.01, ProjectileType::ARROW, 50, 3 } },
};