#include <Assets.h>
#include <Defines.h>
#include <Character.h>

void Assets::LoadAssets()
{
    for (int i = 0; i < HERO_TYPE_COUNT; i++)
    {
        LoadHeroTextures((HeroType)i);
    }
    for (int i = 0; i < ENEMY_TYPE_COUNT; i++)
    {
        LoadEnemyTextures((EnemyType)i);
    }
}

void Assets::LoadHeroTextures(HeroType type)
{
    for (int i = 0; i < 4; i++)
    {
        ASSERT(HeroTextures[type][Character::State::IDLE][i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(HeroTextures[type][Character::State::RUN] [i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(HeroTextures[type][Character::State::HIT] [i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_hit_anim_f0.png"), "Failed to load texture!");
    }
}

void Assets::LoadEnemyTextures(EnemyType type)
{
    for (int i = 0; i < 4; i++)
    {
        ASSERT(EnemyTextures[type][Character::State::IDLE][i].loadFromFile("assets/frames/" + ENEMY_NAMES[type] + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(EnemyTextures[type][Character::State::RUN] [i].loadFromFile("assets/frames/" + ENEMY_NAMES[type] + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
    }
}