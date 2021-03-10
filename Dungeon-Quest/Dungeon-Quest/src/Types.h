#pragma once

static const int HERO_TYPE_COUNT = 3;

enum HeroType 
{ 
    ELF, KNIGHT, WIZZARD 
};

static const std::string HERO_NAMES[HERO_TYPE_COUNT] = 
{ 
    "elf_m", "knight_m", "wizzard_m" 
};

enum HeroState
{
    IDLE, RUN, HIT
};