#include <systems/RenderSystem.hpp>
#include <components/CharacterComponent.h>
#include <components/SpriteComponent.hpp>
#include <components/AttackComponent.hpp>
#include <components/AnimationComponent.hpp>
#include <components/EnemyComponent.hpp>
#include <components/ColliderComponent.hpp>
#include <components/DetectionComponent.hpp>
#include <components/RangeComponent.hpp>
#include <Game.h>
#include <Assets.h>
#include <iostream>

static sf::Vector2f GetCursorWordPosition(const PTR<sf::View>& camera)
{
    sf::Vector2f mouse   = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
    sf::Vector2f winsize = static_cast<sf::Vector2f>(Game::window->getSize());
    return {
        Map(mouse.x, 0, winsize.x, camera->getCenter().x - VIEWPORT_WIDTH  / 2, camera->getCenter().x + VIEWPORT_WIDTH  / 2),
        Map(mouse.y, 0, winsize.y, camera->getCenter().y - VIEWPORT_HEIGHT / 2, camera->getCenter().y + VIEWPORT_HEIGHT / 2)
    };
}
RenderSystem::RenderSystem(const PTR<Level>& level)
    : level(level)
{
}
void RenderSystem::Update(float delta)
{
    level->camera->setCenter({ level->player->GetComponent<ColliderComponent>()->collider.getPosition().x + TILE_SIZE / 2,
                               level->player->GetComponent<ColliderComponent>()->collider.getPosition().y + TILE_SIZE / 2 });

    level->player->GetComponent<SpriteComponent>()->sprite.move(level->player->GetComponent<CharacterComponent>()->speed);
    level->player->GetComponent<ColliderComponent>()->collider.move(level->player->GetComponent<CharacterComponent>()->speed);

    Game::window->setView(*(level->camera));
    Game::window->draw(level->mapSprite);

    for(const auto& wall : level->walls)
    {
        Game::window->draw(wall->GetComponent<ColliderComponent>()->collider);
    }

    for (const auto& item : level->items)
    {
        Game::window->draw(item->GetComponent<SpriteComponent>()->sprite);
        Game::window->draw(item->GetComponent<ColliderComponent>()->collider);
    }

    for (const auto& enemy : level->enemies)
    {
        enemy->GetComponent<SpriteComponent>()->sprite.move(enemy->GetComponent<CharacterComponent>()->speed);
        enemy->GetComponent<ColliderComponent>()->collider.move(enemy->GetComponent<CharacterComponent>()->speed);
        enemy->GetComponent<DetectionComponent>()->detection.move(enemy->GetComponent<CharacterComponent>()->speed);
        enemy->GetComponent<RangeComponent>()->range.move(enemy->GetComponent<CharacterComponent>()->speed);


        Game::window->draw(enemy->GetComponent<SpriteComponent>()->sprite);
        Game::window->draw(enemy->GetComponent<ColliderComponent>()->collider);
        Game::window->draw(enemy->GetComponent<DetectionComponent>()->detection);
        Game::window->draw(enemy->GetComponent<RangeComponent>()->range);
    }

    Game::window->draw(level->player->GetComponent<SpriteComponent>()->sprite);
    Game::window->draw(level->player->GetComponent<ColliderComponent>()->collider);

    for (const auto& projectile : level->projectiles)
    {
        Game::window->draw(projectile->GetComponent<SpriteComponent>()->sprite);
        Game::window->draw(projectile->GetComponent<ColliderComponent>()->collider);
    }
    for (const auto& particle : level->particles)
    {
        Game::window->draw(particle->GetComponent<SpriteComponent>()->sprite);
    }

    sf::Sprite mouse;
    mouse.setTexture(Assets::CursorTexture);
    mouse.setPosition(GetCursorWordPosition(level->camera));
    mouse.setScale({ 0.2F, 0.2F });
    Game::window->draw(mouse);

    Game::window->setView(*(level->uiview));

    sf::Sprite life;
    for (int i = 0; i < level->player->GetComponent<CharacterComponent>()->life; i++)
    {
        life.setTexture(Assets::HeartTexture[0]);
        life.setPosition(static_cast<float>(i * TILE_SIZE + 10), 35.0F);
        Game::window->draw(life);
    }

    for (int i = level->player->GetComponent<CharacterComponent>()->life; i < 3; i++)
    {
        life.setTexture(Assets::HeartTexture[2]);
        life.setPosition(static_cast<float>(i * TILE_SIZE + 10), 35);
        Game::window->draw(life);
    }
}
