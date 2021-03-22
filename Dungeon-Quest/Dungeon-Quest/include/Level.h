#pragma once

#include <SFML/Graphics.hpp>

#include "Defines.h"
#include "components/ColliderComponent.hpp"
#include <vector>
#include <components/EnemyComponent.hpp>
#include <components/ProjectileComponent.hpp>

static const int LEVELS_COUNT = 1;

static const int LEVEL1_WALLS[][4] = 
{
    {  3,  2, 12,  2 }, {  3,  2,  3, 11 }, {  3, 11, 12, 11 }, { 12,  8, 12, 11 }, { 12,  2, 12,  5 }, { 12,  5, 18,  5 }, { 12,  8, 18,  8 },
    { 18,  8, 18, 11 }, { 18,  2, 18,  5 }, { 18,  2, 27,  2 }, { 18, 11, 21, 11 }, { 24, 11, 27, 11 }, { 27,  8, 27, 11 }, { 27,  2, 27,  5 },
    { 27,  5, 33,  5 }, { 27,  8, 33,  8 }, { 33,  2, 33,  5 }, { 33,  2, 42,  2 }, { 33,  8, 33, 11 }, { 33, 11, 42, 11 }, { 42,  2, 42, 11 },
    { 21, 11, 21, 16 }, { 24, 11, 24, 16 }, { 14, 16, 14, 19 }, { 14, 16, 21, 16 }, { 14, 22, 14, 25 }, { 14, 25, 31, 25 }, { 31, 16, 31, 25 },
    { 24, 16, 31, 16 }, { 12, 19, 14, 19 }, { 12, 22, 14, 22 }, {  3, 16, 12, 16 }, {  3, 16,  3, 25 }, {  3, 25,  6, 25 }, {  9, 25, 12, 25 },  
    { 12, 22, 12, 25 }, { 12, 16, 12, 19 }, {  6, 25,  6, 30 }, {  9, 25,  9, 30 }, {  3, 30,  6, 30 }, {  9, 30, 12, 30 }, {  3, 30,  3, 39 }, 
    {  3, 39, 12, 39 }, { 12, 36, 12, 39 }, { 12, 30, 12, 33 }, { 12, 33, 14, 33 }, { 12, 36, 14, 36 }, { 14, 30, 14, 33 }, { 14, 36, 14, 39 },
    { 14, 39, 31, 39 }, { 14, 30, 31, 30 }, { 31, 30, 31, 33 }, { 31, 36, 31, 39 }, { 31, 33, 33, 33 }, { 31, 36, 33, 36 }, { 33, 30, 33, 33 }, 
    { 33, 36, 33, 39 }, { 33, 39, 42, 39 }, { 42, 30, 42, 39 }, { 39, 30, 42, 30 }, { 33, 30, 36, 30 }, { 36, 25, 36, 30 }, { 39, 25, 39, 30 },
    { 33, 25, 36, 25 }, { 39, 25, 42, 25 }, { 33, 16, 33, 25 }, { 42, 16, 42, 25 }, { 33, 16, 42, 16 },
};

struct Level
{
    sf::Texture mapTexture;
    sf::Sprite  mapSprite;

    std::vector<ColliderComponent> walls;
    std::vector<EnemyComponent*> enemies;
    std::vector<PTR<ProjectileComponent>> projectiles;
    std::vector<PTR<ProjectileComponent>> heroProjectiles;

    Level(int level);
};

