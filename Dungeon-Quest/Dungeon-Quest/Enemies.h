#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include <memory>

#define SPRITE_ANIM_NUM 4

enum EnemyType  { BIG_DEMON, BIG_ZOMBIE, CHORT, GOBLIN, ICE_ZOMBIE, IMP, MASKED_ORC, MUDDY, LIZARD_M, LIZARD_F, 
                  OGRE, NECROMANCER, ORC_SHAMAN, ORC_WARRIOR, SKELET, SWAMPY, TINY_ZOMBIE, WOGOL, ZOMBIE };
enum EnemyState { IDLE, RUN };

static const std::string enemies[19] = { "big_demon", "big_zombie", "chort", "goblin", "ice_zombie", "imp", "masked_orc", "muddy", "lizard_m", "lizard_f",
                                         "ogre", "necromancer", "orc_shaman", "orc_warrior", "skelet", "swampy", "tiny_zombie", "wogol", "zombie" };



struct EnemyProperties
{
    float speed;
    float life;
    float damage;

    EnemyProperties() = default;
    EnemyProperties(float speed, float life, float damage) : speed(speed), life(life), damage(damage) { }
};

struct Enemy : public sf::Sprite, public EnemyProperties
{
    EnemyType  type;
    EnemyState state;

    float timer;
    int   index;

    Enemy(EnemyType type, EnemyProperties properties)
        : type(type), state(EnemyState::IDLE), index(0), EnemyProperties(properties.life, properties.damage, properties.speed) { }
    void Update(float delta);
};




struct EnemyAssets
{
    static inline std::map<EnemyType, sf::Texture[2][4]> textures;
    static inline std::map<EnemyType, EnemyProperties> properties;

    static void LoadEnemyAssets()
    {
        for (int i = 0; i < 19; i++)
        {
            LoadTexturesForEnemy(enemies[i], (EnemyType) i);
        }
        
        properties[BIG_DEMON] = EnemyProperties(1.0f, 200.f, 20.f);
    }

    static void LoadTexturesForEnemy(const std::string& name, EnemyType type)
    {
        for (int i = 0; i < SPRITE_ANIM_NUM; i++)
        {
            ASSERT(textures[type][EnemyState::IDLE][i].loadFromFile("assets/frames/" + name + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
            ASSERT(textures[type][EnemyState::RUN] [i].loadFromFile("assets/frames/" + name + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
        }
    }
};

#define SCALE_FACTOR 10.0f

struct EnemyFactory
{
    static PTR<Enemy> CreateEnemy(EnemyType type, float x, float y)
    {
        PTR<Enemy> enemy = CreatePTR<Enemy>(type, EnemyAssets::properties[type]);
        enemy->setScale({ SCALE_FACTOR, SCALE_FACTOR });
        enemy->setPosition(x, y);
        return enemy;
    }

};

void Enemy::Update(float delta)
{
    timer += delta;
    if (timer >= 0.1f)
    {
        setTexture(EnemyAssets::textures[type][state][index]);
        if (++index == SPRITE_ANIM_NUM)
            index = 0;
        timer = 0;
    }
}