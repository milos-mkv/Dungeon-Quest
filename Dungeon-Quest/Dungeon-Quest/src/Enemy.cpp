#include <components/EnemyComponent.hpp>

#include <Assets.h>
#include <Defines.h>
#include <SFML/Graphics.hpp>
#include <Game.h>

constexpr int ENEMY_DETECTION_SIZE = 70;           // Enemy detection box size;

EnemyComponent::EnemyComponent(CharacterType type, float x, float y)
    : CharacterComponent(type, x, y)
{
    detection = DetectionComponent(x - ENEMY_DETECTION_SIZE, y - ENEMY_DETECTION_SIZE, getSize().x + ENEMY_DETECTION_SIZE * 2, 
        getSize().y + ENEMY_DETECTION_SIZE * 2);

    range = RangeComponent(x - CharacterProps[type].range, y - CharacterProps[type].range, getSize().x + CharacterProps[type].range * 2,
        getSize().y + CharacterProps[type].range * 2);

    attackSpeed      = CharacterProps[type].attackSpeed;
    attackSpeedTimer = 0.0f;
}

void EnemyComponent::Update(float delta, HeroComponent* hero)
{
    sf::Vector2f dif = getPosition() - hero->getPosition();
    sf::Vector2f dir = normalize(dif);

    UpdateAttackStatus(delta);

    if(chasing)
    {
        FlipTexture(dif.x > 0);
        speed = { -dir.x * CharacterProps[type].moveSpeed * delta , -dir.y * CharacterProps[type].moveSpeed * delta };
    }
}

void EnemyComponent::Draw()
{
    Game::window->draw(sprite);     // Draw character sprite.
#ifdef DEBUG_MODE
    Game::window->draw(*this);      // Draw character collider box.
    Game::window->draw(detection);  // Draw detection box.
    Game::window->draw(range);      // Draw detection box.
#endif
}