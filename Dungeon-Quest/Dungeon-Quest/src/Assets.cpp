#include <Assets.h>
#include <Defines.h>

void Assets::LoadAssets()
{
    for (int i = 0; i < CHARACTER_TYPE_COUNT; i++)
    {
        LoadCharacterTextures((CharacterType)i);
    }

}

void Assets::LoadCharacterTextures(CharacterType type)
{
    for (int i = 0; i < 4; i++)
    {
        ASSERT(CharacterTextures[type][CharacterState::IDLE][i].loadFromFile("assets/frames/" + CHARACTER_NAMES[type] + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(CharacterTextures[type][CharacterState::RUN] [i].loadFromFile("assets/frames/" + CHARACTER_NAMES[type] + "_run_anim_f"  + std::to_string(i) + ".png"), "Failed to load texture!");
    }
}

