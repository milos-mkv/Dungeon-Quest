#include <Assets.h>
#include <Defines.h>

void Assets::LoadAssets()
{
    for (int i = 0; i < CHARACTER_TYPE_COUNT; i++)
    {
        LoadCharacterTextures((CharacterType)i);
    }
    LoadItemTextures();
    LoadSounds();
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

    for (int i = 0; i < 4; i++)
    {
        ASSERT(ProjectileTextures[ProjectileType::BLUE_FIRE][i].loadFromFile("assets/blue_fire" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(ProjectileTextures[ProjectileType::RED_FIRE] [i].loadFromFile("assets/red_fire" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(ProjectileTextures[ProjectileType::ARROW]    [i].loadFromFile("assets/arrow.png"), "Failed to load texture!");
        ASSERT(ProjectileTextures[ProjectileType::NONE]     [i].loadFromFile("assets/frames/weapon_saw_sword.png"), "Failed to load texture!");
    }
    ASSERT(WeaponTextures[CharacterType::KNIGHT].loadFromFile("assets/frames/weapon_regular_sword.png"), "Failed to load texture!");
    ASSERT(WeaponTextures[CharacterType::ELF].loadFromFile("assets/frames/weapon_knife.png"), "Failed to load texture!");
    ASSERT(WeaponTextures[CharacterType::WIZZARD].loadFromFile("assets/frames/weapon_green_magic_staff.png"), "Failed to load texture!");
    ASSERT(CursorTexture.loadFromFile("assets/cursor1.png"), "Failed to load texture!");

    for (int i = 0; i < 4; i++)
    {
        ASSERT(ParticleTextures[ParticleType::PUF][i].loadFromFile("assets/puf" + std::to_string(i) + ".png"), "Failed to load texture!");        
        ASSERT(ParticleTextures[ParticleType::BROKEN_ARROW][i].loadFromFile("assets/broken_arrow" + std::to_string(i) + ".png"), "Failed to load texture!");
    }
}

void Assets::LoadSounds()
{
    ASSERT(Sounds["Fire"].loadFromFile("assets/fire.wav"), "Failed to load sound!");
}

