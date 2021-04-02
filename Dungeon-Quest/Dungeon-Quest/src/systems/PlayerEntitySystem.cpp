#include <systems/PlayerEntitySystem.hpp>

#include <components/CharacterComponent.h>
#include <components/SpriteComponent.hpp>
#include <components/AttackComponent.hpp>
#include <components/AnimationComponent.hpp>
#include <Game.h>
#include <EntityFactory.hpp>
#include <iostream>

static sf::Vector2f VecAdd(const sf::Vector2f& vec, int i)
{
    return { vec.x + i, vec.y + i };
}

static sf::Vector2f GetCursorWordPosition(const PTR<sf::View>& camera)
{
    sf::Vector2f mouse = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
    sf::Vector2f winsize = static_cast<sf::Vector2f>(Game::window->getSize());
    return {
        Map(mouse.x, 0, winsize.x, camera->getCenter().x - VIEWPORT_WIDTH  / 2, camera->getCenter().x + VIEWPORT_WIDTH  / 2),
        Map(mouse.y, 0, winsize.y, camera->getCenter().y - VIEWPORT_HEIGHT / 2, camera->getCenter().y + VIEWPORT_HEIGHT / 2)
    };
}
static void FlipTexture(CharacterType type, sf::Sprite& sprite, bool flip);

PlayerEntitySystem::PlayerEntitySystem(const PTR<Level>& level)
    : level(level)
{
}

void PlayerEntitySystem::Update(float delta)
{
    auto characterComponent = level->player->GetComponent<CharacterComponent>();
    auto spriteComponent    = level->player->GetComponent<SpriteComponent>();
    auto attackComponent    = level->player->GetComponent<AttackComponent>();
    auto animationComponent = level->player->GetComponent<AnimationComponent>();
    auto colliderComponent  = level->player->GetComponent<ColliderComponent>();

    characterComponent->speed = { 0, 0 };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        characterComponent->speed.x = -CharacterProperties[characterComponent->type].moveSpeed * delta;
        FlipTexture(characterComponent->type, spriteComponent->sprite, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        characterComponent->speed.x = CharacterProperties[characterComponent->type].moveSpeed * delta;
        FlipTexture(characterComponent->type, spriteComponent->sprite, false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        characterComponent->speed.y = -CharacterProperties[characterComponent->type].moveSpeed * delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        characterComponent->speed.y = CharacterProperties[characterComponent->type].moveSpeed * delta;
    }

    characterComponent->state = (characterComponent->speed.x || characterComponent->speed.y) ? CharacterState::RUN : CharacterState::IDLE;
    
    attackComponent->UpdateAttackStatus(delta);
    UpdatePlayerAnimation(animationComponent, delta);
    spriteComponent->sprite.setTexture(Assets::CharacterTextures[characterComponent->type][characterComponent->state][animationComponent->index]);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && attackComponent->timer == 0.f)
    {
        attackComponent->timer += delta;
        level->projectiles.push_back(EntityFactory::CreateProjectile(CharacterProperties[characterComponent->type].projectileType, 
            colliderComponent->GetCenter(), VecAdd(GetCursorWordPosition(level->camera) , RandInt(-7, 7)), true));
    }
}

void PlayerEntitySystem::UpdatePlayerAnimation(const PTR<AnimationComponent>& animationComponent, float delta) const
{
    if ((animationComponent->timer += delta) >= animationComponent->changeTimer)
    {
        animationComponent->index = (animationComponent->index + 1) % 4;
        animationComponent->timer = 0;
    }
}

static void FlipTexture(CharacterType type, sf::Sprite& sprite, bool flip)
{
    if (flip)
        sprite.setTextureRect(sf::IntRect((int)CharacterProperties[type].spriteSize.x, 0, -(int)CharacterProperties[type].spriteSize.x, (int)CharacterProperties[type].spriteSize.y));
    else
        sprite.setTextureRect(sf::IntRect(0, 0, (int)CharacterProperties[type].spriteSize.x, (int)CharacterProperties[type].spriteSize.y));
}