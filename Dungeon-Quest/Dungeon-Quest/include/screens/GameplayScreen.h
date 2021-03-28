#pragma once

#include <screens/Screen.hpp>
#include <Defines.h>
#include <SFML/Graphics.hpp>
#include <Level.hpp>
#include <systems/CollisionDetectionSystem.hpp>
#include <systems/EnemyEntitySystem.hpp>
#include <systems/ParticleEntitySystem.hpp>
#include <systems/PlayerEntitySystem.hpp>
#include <systems/ProjectileEntitySystem.hpp>
#include <systems/RenderSystem.hpp>

#include <Engine.hpp>

struct GameplayScreen : public IScreen
{
    PTR<Level>                    level;
    PTR<CollisionDetectionSystem> collisionDetectionSystem;
    PTR<EnemyEntitySystem>        enemySystem;
    PTR<PlayerEntitySystem>       playerSystem;
    PTR<ProjectileEntitySystem>   projectileSystem;
    PTR<ParticleEntitySystem>     particleSystem;
    PTR<RenderSystem>             renderSystem;

    PTR<Engine> engine;

    GameplayScreen();
    void Render(float delta) override;
    virtual ~GameplayScreen() = default;
};

