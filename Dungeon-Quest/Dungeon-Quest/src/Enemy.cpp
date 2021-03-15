#include <components/EnemyComponent.hpp>

#include <Assets.h>
#include <Defines.h>
#include <SFML/Graphics.hpp>
#include <Game.h>

#define ENEMY_SPEED 50

static sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    return (length != 0) ? sf::Vector2f(source.x / length, source.y / length) : source;
}

EnemyComponent::EnemyComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    detection = DetectionComponent(x - CharacterColliderSizes[type].x * 3, y - CharacterColliderSizes[type].y * 2, 
        CharacterColliderSizes[type].x * 7, CharacterColliderSizes[type].y * 5);
}

void EnemyComponent::Update(float delta, HeroComponent* hero)
{
    sf::Vector2f diff = getPosition() - hero->getPosition();
    sf::Vector2f dir  = normalize(diff);

    if(chasing)
    {
        FlipTexture(diff.x > 0);
        speed = { -dir.x * ENEMY_SPEED * delta , -dir.y * ENEMY_SPEED * delta };
    }
}

void EnemyComponent::Draw()
{
    Game::window->draw(sprite);     // Draw character sprite.
    Game::window->draw(*this);      // Draw character collider box.
    Game::window->draw(detection);  // Draw detection box.
}