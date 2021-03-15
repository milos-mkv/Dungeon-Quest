
#include "GameplayScreen.h"
#include "Game.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Defines.h"

GameplayScreen::GameplayScreen()
{
    level  =new Level(1);
    camera = new sf::View(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    hero   = new HeroComponent(CharacterType::WIZZARD, 100, 100);
    enemy  = new EnemyComponent(CharacterType::OGRE, 350, 100);
}

void GameplayScreen::Render(float delta)
{
    hero->ProcessInput(delta);

    enemy->Update(delta, hero);
    CheckHeroCollision();

    hero->Update(delta);

    enemy->UpdateAnimation(delta);
    camera->setCenter({ hero->getPosition().x + TILE_SIZE / 2, hero->getPosition().y + TILE_SIZE / 2 });
    
    
    enemy->move(enemy->speed);
    enemy->sprite.move(enemy->speed);


    Game::window->setView(*camera);
    Game::window->draw(level->mapSprite);
    hero->Draw();
    Game::window->draw(*enemy);

    Game::window->draw(*enemy);
    Game::window->draw(enemy->sprite);


    for (auto& wall : level->walls)
    {
        Game::window->draw(wall);
    }
}

GameplayScreen::~GameplayScreen()
{
}

#define HERO_WALL_X_AABB(a, b) \
    (a->getPosition().x + a->speed.x + a->getSize().x >= b.getPosition().x &&  b.getPosition().x + b.getSize().x >= a->getPosition().x + a->speed.x) \
    && (a->getPosition().y + a->getSize().y >= b.getPosition().y && b.getPosition().y + b.getSize().y >= a->getPosition().y)

#define HERO_WALL_Y_AABB(a, b) \
    (a->getPosition().x + a->getSize().x >= b.getPosition().x && b.getPosition().x + b.getSize().x >= a->getPosition().x) \
    && (a->getPosition().y + a->speed.y + a->getSize().y >= b.getPosition().y && b.getPosition().y + b.getSize().y >= a->getPosition().y + a->speed.y)

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

        if (HERO_WALL_X_AABB(enemy, wall))
        {
            enemy->speed.x = 0;
        }
        if (HERO_WALL_Y_AABB(enemy, wall))
        {
            enemy->speed.y = 0;
        }
    }
}
