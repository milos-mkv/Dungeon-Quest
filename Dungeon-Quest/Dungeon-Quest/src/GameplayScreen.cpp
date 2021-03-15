
#include "GameplayScreen.h"
#include "Game.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <Assets.h>
#include "Defines.h"

static sf::View* uiview;

GameplayScreen::GameplayScreen()
{
    level  = new Level(1);
    camera = new sf::View(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    hero   = new HeroComponent(CharacterType::KNIGHT, 100, 100);
    uiview = new sf::View(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    level->enemies.push_back(new EnemyComponent(CharacterType::BIG_DEMON, 350, 100));
    level->enemies.push_back(new EnemyComponent(CharacterType::ORC_SHAMAN, 350, 350));
}

void GameplayScreen::Render(float delta)
{
    hero->ProcessInput(delta);

    for(EnemyComponent* enemy : level->enemies)
        enemy->Update(delta, hero);
    CheckHeroCollision();

    hero->Update(delta);

    for (EnemyComponent* enemy : level->enemies)
        enemy->UpdateAnimation(delta);
    camera->setCenter({ hero->getPosition().x + TILE_SIZE / 2, hero->getPosition().y + TILE_SIZE / 2 });
    
    
    for (EnemyComponent* enemy : level->enemies)
    {
        enemy->move(enemy->speed);
        enemy->sprite.move(enemy->speed);
        enemy->detection.move(enemy->speed);
    }

    Game::window->setView(*camera);
    Game::window->draw(level->mapSprite);
    for (EnemyComponent* enemy : level->enemies)
        enemy->Draw();
    hero->Draw();


    for (auto& wall : level->walls)
    {
        Game::window->draw(wall);
    }


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
    delete camera;
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

void GameplayScreen::CheckHeroCollision()
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
        if (CheckCollisionX(hero, enemy)) hero->speed.x = 0;
        if (CheckCollisionY(hero, enemy)) hero->speed.y = 0;


        bool chasing = false;
        if (CheckCollisionX(hero, &(enemy->detection)) || CheckCollisionY(hero, &(enemy->detection)))
        {
            enemy->chasing = true;
            enemy->state = CharacterState::RUN;
        }
        else
        {
            enemy->speed = { 0, 0 };
            enemy->state = CharacterState::IDLE;
        }

        if (CheckCollisionX(enemy, hero)) enemy->speed.x = 0;
        if (CheckCollisionY(enemy, hero)) enemy->speed.y = 0;
    }
    
}
