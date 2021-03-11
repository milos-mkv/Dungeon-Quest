
#include "GameplayScreen.h"
#include "Game.h"
#include <iostream>

#include "Defines.h"

GameplayScreen::GameplayScreen()
{
    
    level  = CreatePTR<Level>(1);
    camera = CreatePTR<Camera>(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    hero   = CreatePTR<Hero>(HeroType::KNIGHT, 100, 100);
    enemy  = CreatePTR<Enemy>(EnemyType::OGRE, 100, 100);
}

void GameplayScreen::Render(float delta)
{
    hero->ProcessInput(delta);

    CheckHeroCollision();

    hero->Update(delta);
    enemy->state = Character::State::RUN;

    enemy->UpdateAnimation(delta);
    camera->setCenter({ hero->getPosition().x + TILE_SIZE / 2, hero->getPosition().y + TILE_SIZE / 2 });
    
    Game::window->setView(*camera);
    Game::window->draw(level->mapSprite);
    Game::window->draw(*hero);
    Game::window->draw(*enemy);
   // Game::window->draw(enemy->collider);
    Game::window->draw(hero->collider);

    for (auto& wall : level->walls)
    {
        Game::window->draw(wall);
    }
}

GameplayScreen::~GameplayScreen()
{
}

#define HERO_WALL_X_AABB(a, b) \
    (a->collider.getPosition().x + a->speed.x + a->collider.getSize().x >= b.getPosition().x &&  b.getPosition().x + b.getSize().x >= a->collider.getPosition().x + a->speed.x) \
    && (a->collider.getPosition().y + a->collider.getSize().y >= b.getPosition().y && b.getPosition().y + b.getSize().y >= a->collider.getPosition().y)

#define HERO_WALL_Y_AABB(a, b) \
    (a->collider.getPosition().x + a->collider.getSize().x >= b.getPosition().x && b.getPosition().x + b.getSize().x >= a->collider.getPosition().x) \
    && (a->collider.getPosition().y + a->speed.y + a->collider.getSize().y >= b.getPosition().y && b.getPosition().y + b.getSize().y >= a->collider.getPosition().y + a->speed.y)

void GameplayScreen::CheckHeroCollision()
{
    for (auto& wall : level->walls)
    {
        if (HERO_WALL_X_AABB(hero, wall))
        {
            hero->speed.x = 0;
        }

        if (HERO_WALL_Y_AABB(hero, wall))
        {
            hero->speed.y = 0;
        }
    }
}
