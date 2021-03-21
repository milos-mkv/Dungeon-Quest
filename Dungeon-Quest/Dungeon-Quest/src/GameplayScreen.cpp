
#include "GameplayScreen.h"
#include "Game.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <Assets.h>
#include "Defines.h"

static sf::View* uiview;

#include <components/ProjectileComponent.hpp>

GameplayScreen::GameplayScreen()
{
    level  = new Level(1);
    camera = new sf::View(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    hero   = new HeroComponent(CharacterType::WIZZARD, 100, 100);
    uiview = new sf::View(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    level->enemies.push_back(new EnemyComponent(CharacterType::BIG_ZOMBIE,  350, 100));
    level->enemies.push_back(new EnemyComponent(CharacterType::ORC_SHAMAN, 350, 350));
    level->enemies.push_back(new EnemyComponent(CharacterType::SKELET, 250, 100));
    level->enemies.push_back(new EnemyComponent(CharacterType::MASKED_ORC, 270, 100));
}

void GameplayScreen::Render(float delta)
{
    hero->ProcessInput(delta);

    for(EnemyComponent* enemy : level->enemies)
        enemy->Update(delta, hero);
    CheckHeroCollision(delta);

    hero->Update(delta);

    for (EnemyComponent* enemy : level->enemies)
        enemy->UpdateAnimation(delta);
    camera->setCenter({ hero->getPosition().x + TILE_SIZE / 2, hero->getPosition().y + TILE_SIZE / 2 });
    
    
    for (EnemyComponent* enemy : level->enemies)
    {
        enemy->move(enemy->speed);
        enemy->sprite.move(enemy->speed);
        enemy->detection.move(enemy->speed);
        enemy->range.move(enemy->speed);
    }

    Game::window->setView(*camera);
    Game::window->draw(level->mapSprite);
    for (EnemyComponent* enemy : level->enemies)
        enemy->Draw();
    hero->Draw();

    for(auto iter = level->projectiles.begin(); iter < level->projectiles.end(); iter++)
    {
        if ((*iter)->done)
        {
            level->projectiles.erase(iter);       
            continue;
        }
        (*iter)->Update(delta);
        Game::window->draw(**iter);
    }
#ifdef DEBUG_MODE
    for (auto& wall : level->walls)
    {
        Game::window->draw(wall);
    }
#endif

    Game::window->setView(*uiview);

    sf::Sprite life;

    for (int i = 0; i < hero->life; i++)
    {
        life.setTexture(Assets::HeartTexture[0]);
        life.setPosition(i * TILE_SIZE + 10, 35);
        Game::window->draw(life);

    }
}

GameplayScreen::~GameplayScreen()
{
    delete level;
    delete hero;
    delete uiview;
    delete camera;
    for (EnemyComponent* enemy : level->enemies)
        delete enemy;
}

static bool CheckCollisionX(CharacterComponent* c1, sf::RectangleShape *c2)
{
    return (c1->getPosition().x + c1->speed.x + c1->getSize().x > c2->getPosition().x && c2->getPosition().x + c2->getSize().x >= c1->getPosition().x + c1->speed.x)
        && (c1->getPosition().y + c1->getSize().y >= c2->getPosition().y && c2->getPosition().y + c2->getSize().y >= c1->getPosition().y);
}

static bool CheckCollisionY(CharacterComponent* c1, sf::RectangleShape* c2)
{
    return (c1->getPosition().x + c1->getSize().x >= c2->getPosition().x && c2->getPosition().x + c2->getSize().x >= c1->getPosition().x)
        && (c1->getPosition().y + c1->speed.y + c1->getSize().y >= c2->getPosition().y && c2->getPosition().y + c2->getSize().y >= c1->getPosition().y + c1->speed.y);
}

static bool CheckCollision(sf::RectangleShape* c1, sf::RectangleShape* c2)
{
    return (c1->getPosition().x + c1->getSize().x >= c2->getPosition().x && c2->getPosition().x + c2->getSize().x >= c1->getPosition().x)
        && (c1->getPosition().y + c1->getSize().y >= c2->getPosition().y && c2->getPosition().y + c2->getSize().y >= c1->getPosition().y);

}

void GameplayScreen::CheckHeroCollision(float delta)
{

    for (auto& wall : level->walls)
    {
        if (CheckCollisionX(hero, &wall)) hero->speed.x = 0;
        if (CheckCollisionY(hero, &wall)) hero->speed.y = 0;
   
        for (EnemyComponent* enemy : level->enemies)
        {
            if (CheckCollisionX(enemy, &wall)) enemy->speed.x = 0;
            if (CheckCollisionY(enemy, &wall)) enemy->speed.y = 0;
        }
        
    }

    for (EnemyComponent* enemy : level->enemies)
    {
        if (!enemy->chasing && (CheckCollisionX(hero, &(enemy->detection)) || CheckCollisionY(hero, &(enemy->detection))))
        {
            enemy->chasing = true;
            enemy->state   = CharacterState::RUN;
        }

        if (CheckCollisionX(hero, &(enemy->range)) || CheckCollisionY(hero, &(enemy->range)))
        {
            enemy->speed = { 0, 0 };
            enemy->state = CharacterState::IDLE;
            if (enemy->attackSpeedTimer == 0.f && enemy->attackType == CharacterAttackType::RANGED)
            {
                enemy->attackSpeedTimer += delta;
                sf::Vector2f to = { hero->GetCenter().x + RandFloat(-15, 15), hero->GetCenter().y + RandFloat(-15, 15) };
                level->projectiles.push_back(CreatePTR<ProjectileComponent>(CharacterProperties[enemy->type].projectileType, enemy->GetCenter(),to));
            }
        }
    }

    for (auto iter = level->projectiles.begin(); iter < level->projectiles.end(); iter++)
    {
        if (CheckCollision(hero, (*iter).get()))
        {
            level->projectiles.erase(iter);
            hero->life--;
            continue;
        }
    }


    if (hero->speed.x && hero->speed.y)
    {
        hero->speed = { hero->speed.x / 1.2f, hero->speed.y / 1.2f };
    }
}
