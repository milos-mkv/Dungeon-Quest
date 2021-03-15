#pragma once

#include <SFML/System.hpp>

#include <components/ColliderComponent.hpp>
#include <components/AnimationComponent.h>

static const int CHARACTER_TYPE_COUNT = 6;

static const std::string CHARACTER_NAMES[CHARACTER_TYPE_COUNT] =
{
    "elf_m", "knight_m", "wizzard_m",  "ogre", "orc_shaman", "orc_warrior"
};

enum CharacterType  { ELF, KNIGHT, WIZZARD, OGRE, ORC_SHAMAN, ORC_WARRIOR };
enum CharacterState { IDLE, RUN, HIT };

struct CharacterComponent : public AnimationComponent, public ColliderComponent
{
    CharacterType  type;
    CharacterState state;
    sf::Sprite     sprite;
    sf::Vector2f   speed;

    CharacterComponent(CharacterType type, float x, float y);
    void UpdateAnimation(float delta);
    void Draw();
};

static std::map<CharacterType, sf::Vector2f> CharacterSpriteSizes =
{
    { CharacterType::ELF,         { 16, 28 } },
    { CharacterType::KNIGHT,      { 16, 28 } },
    { CharacterType::WIZZARD,     { 16, 28 } },
    { CharacterType::OGRE,        { 32, 32 } },
    { CharacterType::ORC_SHAMAN,  { 16, 20 } },
    { CharacterType::ORC_WARRIOR, { 16, 20 } }
};

static std::map<CharacterType, sf::Vector2f> CharacterColliderSizes =
{
    { CharacterType::ELF,         { 16, 16 } },
    { CharacterType::KNIGHT,      { 16, 16 } },
    { CharacterType::WIZZARD,     { 16, 16 } },
    { CharacterType::OGRE,        { 25, 25 } },
    { CharacterType::ORC_SHAMAN,  { 16, 16 } },
    { CharacterType::ORC_WARRIOR, { 16, 16 } }
};