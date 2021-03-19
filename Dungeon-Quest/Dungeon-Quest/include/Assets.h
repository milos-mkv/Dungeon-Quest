#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <map>
#include <components/CharacterComponent.h>

struct Assets
{
    static inline std::map<CharacterType, sf::Texture[3][4]> CharacterTextures;
    static inline sf::Texture HeartTexture[3];
    static inline sf::Texture FireTextures[4];
    static void LoadAssets();

private:
    static void LoadCharacterTextures(CharacterType type);
    static void LoadItemTextures();
};

