#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <map>
#include <components/CharacterComponent.h>
#include <components/ParticleComponent.hpp>
#include <string>
#include <array>

#include <components/ChestComponent.hpp>
struct Assets
{
    static inline std::map<CharacterType, std::array<std::array<sf::Texture, 4>, 3>> CharacterTextures;
    static inline std::array<sf::Texture, 3> HeartTexture;
    static inline std::map<ProjectileType, std::array<sf::Texture,4>> ProjectileTextures;
    static inline std::map<CharacterType, sf::Texture> WeaponTextures;
    static inline std::map<ParticleType, std::array<sf::Texture, 4>> ParticleTextures;
    static inline sf::Texture CursorTexture;
    static inline std::array<sf::Texture,1> MapTextures;
    static inline sf::Texture GameTitleTexture;
    static inline sf::Texture CrateTexture;
    static inline std::map< ChestType, std::array<sf::Texture, 3>> ChestTextures;
    static inline std::array<sf::Texture, 4> CoinTextures;

    static void LoadAssets();

private:
    static void LoadCharacterTextures(CharacterType type);
    static void LoadItemTextures();
};

