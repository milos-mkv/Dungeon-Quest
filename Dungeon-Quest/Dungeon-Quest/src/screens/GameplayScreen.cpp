
#include <screens/GameplayScreen.h>
#include <Game.h>
#include <iostream>
#include <Assets.h>

GameplayScreen::GameplayScreen()
{
    level  = CreatePTR<Level>(1);
    engine = CreatePTR <Engine>();

    engine->AddSystem<PlayerEntitySystem>(CreatePTR<PlayerEntitySystem>(level));
    engine->AddSystem<EnemyEntitySystem>(CreatePTR<EnemyEntitySystem>(level));
    engine->AddSystem<CollisionDetectionSystem>(CreatePTR<CollisionDetectionSystem>(level));
    engine->AddSystem<ProjectileEntitySystem>(CreatePTR<ProjectileEntitySystem>(level));
    engine->AddSystem<ParticleEntitySystem>(CreatePTR<ParticleEntitySystem>(level));
    engine->AddSystem<RenderSystem>(CreatePTR<RenderSystem>(level));
}

void GameplayScreen::Render(float delta)
{
    engine->Update(delta);
}