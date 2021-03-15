#pragma once
#include "Defines.h"
#include "Screen.h"
#include "Level.h"

#include <components/HeroComponent.hpp>
#include <components/EnemyComponent.hpp>


struct GameplayScreen : public Screen
{
    Level* level;
    sf::View* camera;
    HeroComponent* hero;
    EnemyComponent* enemy;

    GameplayScreen();

    void Render(float delta) override;

    ~GameplayScreen();
private:
    void CheckHeroCollision();
};

