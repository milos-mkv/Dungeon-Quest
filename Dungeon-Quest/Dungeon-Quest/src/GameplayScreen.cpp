#include "GameplayScreen.h"
#include "Game.h"
#include <iostream>

#include "Defines.h"

sf::Vector2f lpos;
GameplayScreen::GameplayScreen()
{
    
    level  = CreatePTR<Level>(1);
    camera = CreatePTR<Camera>(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    hero   = CreatePTR<Hero>(HeroType::KNIGHT, 100, 100);


}

static bool AABBCheck(CollisionBox& a, CollisionBox& b)
{
    bool collidingX = a.getPosition().x + a.getSize().x >= b.getPosition().x && b.getPosition().x + b.getSize().x >= a.getPosition().x;
    bool collidingY = a.getPosition().y + a.getSize().y >= b.getPosition().y && b.getPosition().y + b.getSize().y >= a.getPosition().y;

    return collidingX && collidingY;
}

void GameplayScreen::Render(float delta)
{
    lpos = hero->getPosition();
    hero->ProcessInput(delta);

    for (auto& wall : level->walls)
    {

      //  float x = hero->box.getPosition().x + hero->speed.x;
      //  float y = hero->box.getPosition().y + hero->speed.y;
        
        bool collidingX = hero->box.getPosition().x + hero->speed.x + hero->box.getSize().x >= wall.getPosition().x && 
                          wall.getPosition().x + wall.getSize().x >= hero->box.getPosition().x + hero->speed.x;
        bool collidingY = hero->box.getPosition().y + hero->box.getSize().y >= wall.getPosition().y &&
                          wall.getPosition().y + wall.getSize().y >= hero->box.getPosition().y ;

       
        if (collidingX && collidingY)
        {
            

            hero->speed.x = 0;
        }
        collidingX = hero->box.getPosition().x + hero->box.getSize().x >= wall.getPosition().x &&
            wall.getPosition().x + wall.getSize().x >= hero->box.getPosition().x ;
        collidingY = hero->box.getPosition().y + hero->speed.y + hero->box.getSize().y >= wall.getPosition().y &&
            wall.getPosition().y + wall.getSize().y >= hero->box.getPosition().y + hero->speed.y;


        if (collidingX && collidingY)
        {
            hero->speed.y = 0;
        }
        /*
        if(x<y)
        {
        if (AABBCheck(hero->box, wall))
        {
            hero->setPosition({lpos.x, hero->getPosition().y});
            hero->box.setPosition(hero->getPosition().x, hero->getPosition().y + HERO_HEIGHT_OFFSET);

        }

        if (AABBCheck(hero->box, wall))
        {
            hero->setPosition({ hero->getPosition().x, lpos.y });
            hero->box.setPosition(hero->getPosition().x, hero->getPosition().y + HERO_HEIGHT_OFFSET);
        }
        }
        */
          //  hero->setPosition({hero->getPosition().x - hero->speed, hero->getPosition().y})
            /*
            if (hero->box.getPosition().x > wall.getPosition().x && hero->box.getSize().x + hero->box.getPosition().x < wall.getPosition().x + wall.getSize().x)
            {
                pos.y = hero->box.getPosition().y < wall.getPosition().y ? wall.getPosition().y - hero->box.getSize().y : wall.getPosition().y + wall.getSize().y;
                pos.y -= HERO_HEIGHT_OFFSET;
            }
            else if (hero->box.getPosition().y > wall.getPosition().y && hero->box.getSize().y + hero->box.getPosition().y < wall.getPosition().y + wall.getSize().y)
            {
                pos.x = hero->box.getPosition().x < wall.getPosition().x ? wall.getPosition().x - hero->box.getSize().x : wall.getPosition().x + wall.getSize().x;
            }
            else {
            }
            hero->setPosition(pos);
            hero->box.setPosition(hero->getPosition().x, hero->getPosition().y + HERO_HEIGHT_OFFSET);
            */
        

    }
    hero->Update(delta);


    camera->setCenter(hero->getPosition());
    
    Game::window->setView(*camera);
    Game::window->draw(level->mapSprite);
    Game::window->draw(*hero);
    Game::window->draw(hero->box);
    for (auto& wall : level->walls)
    {
        Game::window->draw(wall);
    }
}

GameplayScreen::~GameplayScreen()
{
}
