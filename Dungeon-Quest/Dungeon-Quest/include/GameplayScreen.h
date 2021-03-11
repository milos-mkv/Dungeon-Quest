#pragma once
#include "Defines.h"
#include "Screen.h"
#include "Level.h"
#include "Camera.h"
#include "Hero.h"
#include "Enemy.h"

struct GameplayScreen : public Screen
{
    PTR<Level> level;
    PTR<Camera> camera;
    PTR<Hero> hero;
    PTR<Enemy> enemy;

    GameplayScreen();

    void Render(float delta) override;

    ~GameplayScreen();
private:
    void CheckHeroCollision();
};

