#include <components/EnemyComponent.hpp>

#include <Assets.h>
#include <Defines.h>
#include <SFML/Graphics.hpp>
#include <Game.h>

#define ENEMY_SPEED          50
#define ENEMY_DETECTION_SIZE 70

static const int EnemyRanges[2] = { 1, 50 };

static sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    return (length != 0) ? sf::Vector2f(source.x / length, source.y / length) : source;
}

EnemyComponent::EnemyComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    detection = DetectionComponent(x - ENEMY_DETECTION_SIZE, y - ENEMY_DETECTION_SIZE, 
        CharacterColliderSizes[type].x + ENEMY_DETECTION_SIZE * 2, CharacterColliderSizes[type].y + ENEMY_DETECTION_SIZE * 2);

    range = RangeComponent(x - EnemyRanges[CharacterAttackTypes[type]], y - EnemyRanges[CharacterAttackTypes[type]], 
        CharacterColliderSizes[type].x + EnemyRanges[CharacterAttackTypes[type]] * 2, CharacterColliderSizes[type].y + EnemyRanges[CharacterAttackTypes[type]] * 2);
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
    Game::window->draw(range);  // Draw detection box.
}