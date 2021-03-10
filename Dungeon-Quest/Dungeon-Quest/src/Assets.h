#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <map>
#include <string>

#include "Types.h"

struct Assets
{
    static inline std::map<HeroType, sf::Texture[3][4]> HeroTextures;

    static void LoadAssets();
private:
    static void LoadHeroTextures(HeroType type);
};

