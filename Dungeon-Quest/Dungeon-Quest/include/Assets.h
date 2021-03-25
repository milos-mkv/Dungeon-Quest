#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <map>
#include <components/CharacterComponent.h>
#include <components/ParticleComponent.hpp>
#include <string>

struct Assets
{
    static inline std::map<CharacterType, sf::Texture[3][4]> CharacterTextures;
    static inline sf::Texture HeartTexture[3];
    static inline std::map<ProjectileType, sf::Texture[4]> ProjectileTextures;
    static inline std::map<CharacterType, sf::Texture> WeaponTextures;
    static inline std::map<ParticleType, sf::Texture[4]> ParticleTextures;
    static inline sf::Texture CursorTexture;

    static inline std::map<std::string, sf::SoundBuffer> Sounds;
    static void LoadAssets();

private:
    static void LoadCharacterTextures(CharacterType type);
    static void LoadItemTextures();
    static void LoadSounds();
};

