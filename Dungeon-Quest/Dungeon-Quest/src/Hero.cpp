#include "Hero.h"
/*
void HeroAssets::LoadHeroAssets()
{
    for (int i = 0; i < HERO_TYPE_COUNT; i++)
    {
        LoadTexturesForHero(HEROES[i], (Hero::Type)i);
    }
}

void HeroAssets::LoadTexturesForHero(const std::string& name, Hero::Type type)
{
    for (int i = 0; i < SPRITE_ANIM_NUM; i++)
    {
        ASSERT(textures[type][Hero::State::IDLE][i].loadFromFile("assets/frames/" + name + "_idle_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(textures[type][Hero::State::RUN] [i].loadFromFile("assets/frames/" + name + "_run_anim_f" + std::to_string(i) + ".png"), "Failed to load texture!");
        ASSERT(textures[type][Hero::State::HIT] [i].loadFromFile("assets/frames/" + name + "_hit_anim_f0.png"), "Failed to load texture!");
    }
}

PTR<Hero> HeroFactory::CreateHero(Hero::Type type, float x, float y)
{
    PTR<Hero> hero = CreatePTR<Hero>(type);
    hero->setPosition({ x - 8, y - 14 });
    hero->setTexture(HeroAssets::textures[type][Hero::State::IDLE][0]);
    return hero;
}

void Hero::SetState(State state)
{
    this->state = state;
    setTexture(HeroAssets::textures[type][state][0]);
}

void Hero::Update(float delta)
{
    state = Hero::State::IDLE;

    KeyboardInput(delta);

    timer += delta;
    if (timer >= 0.12f)
    {
        setTexture(HeroAssets::textures[type][state][index]);
        if (++index == SPRITE_ANIM_NUM)
            index = 0;
        timer = 0;
    }
}

void Hero::KeyboardInput(float delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move({ -speed * delta, 0 });
        state = Hero::State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move({ speed * delta, 0 });
        state = Hero::State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        move({ 0, -speed * delta });
        state = Hero::State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move({ 0, speed * delta });
        state = Hero::State::RUN;
    }
}
*/