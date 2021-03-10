#include "Assets.h"
#include "Defines.h"

void Assets::LoadAssets()
{
    for (int i = 0; i < HERO_TYPE_COUNT; i++)
    {
        LoadHeroTextures((HeroType) i);
    }
}

void Assets::LoadHeroTextures(HeroType type)
{
    for (int i = 0; i < 4; i++)
    {
        ASSERT(HeroTextures[type][HeroState::IDLE][i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(HeroTextures[type][HeroState::RUN] [i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_run_anim_f" +  std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(HeroTextures[type][HeroState::HIT] [i].loadFromFile("assets/frames/" + HERO_NAMES[type] + "_hit_anim_f0.png"), "Failed to load texture!");

    }
}
