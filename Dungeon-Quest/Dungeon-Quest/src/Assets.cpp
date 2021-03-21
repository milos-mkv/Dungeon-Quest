#include <Assets.h>
#include <Defines.h>

void Assets::LoadAssets()
{
    for (int i = 0; i < CHARACTER_TYPE_COUNT; i++)
    {
        LoadCharacterTextures((CharacterType)i);
    }
    LoadItemTextures();
}

void Assets::LoadCharacterTextures(CharacterType type)
{
    for (int i = 0; i < 4; i++)
    {
        ASSERT(CharacterTextures[type][CharacterState::IDLE][i].loadFromFile("assets/frames/" + CHARACTER_NAMES[type] + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(CharacterTextures[type][CharacterState::RUN] [i].loadFromFile("assets/frames/" + CHARACTER_NAMES[type] + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
        if(type == CharacterType::ELF || type == CharacterType::KNIGHT || type == CharacterType::WIZZARD)
        ASSERT(CharacterTextures[type][CharacterState::HIT] [i].loadFromFile("assets/frames/" + CHARACTER_NAMES[type] + "_hit_anim_f0.png"), "Failed to load texture!");
    }
}

void Assets::LoadItemTextures()
{
    ASSERT(HeartTexture[0].loadFromFile("assets/frames/ui_heart_full.png"),  "Failed to load texture!");
    ASSERT(HeartTexture[1].loadFromFile("assets/frames/ui_heart_half.png"),  "Failed to load texture!");
    ASSERT(HeartTexture[2].loadFromFile("assets/frames/ui_heart_empty.png"), "Failed to load texture!");
  //  for (int i = 0; i < 4; i++)
  //  {
  //      ASSERT(FireTextures[i].loadFromFile("assets/fire" + std::to_string(i) + ".png"), "Failed to load texture!");
  //  }
    ASSERT(FireTextures[0].loadFromFile("assets/arrow.png"), "Failed to load texture!");
    ASSERT(FireTextures[1].loadFromFile("assets/arrow.png"), "Failed to load texture!");
    ASSERT(FireTextures[2].loadFromFile("assets/arrow.png"), "Failed to load texture!");
    ASSERT(FireTextures[3].loadFromFile("assets/arrow.png"), "Failed to load texture!");

}

