#include <components/EnemyComponent.hpp>

#include <Assets.h>
#include <Defines.h>
#include <SFML/Graphics.hpp>

#define ENEMY_SPEED 50

static sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    return (length != 0) ? sf::Vector2f(source.x / length, source.y / length) : source;
}

EnemyComponent::EnemyComponent(CharacterType type, float x, float y) 
    : CharacterComponent(type, x, y)
{
    sprite.setTextureRect(sf::IntRect(CharacterSpriteSizes[type].x, 0, -CharacterSpriteSizes[type].x, CharacterSpriteSizes[type].y));

}

void EnemyComponent::Update(float delta, HeroComponent* hero)
{
    sf::Vector2f diff = getPosition() - hero->getPosition();
    sf::Vector2f dir  = normalize(diff);

    if (sqrt(diff.x * diff.x + diff.y * diff.y) > 1)
    {
        if(diff.x > 0)
            sprite.setTextureRect(sf::IntRect(CharacterSpriteSizes[type].x, 0, -CharacterSpriteSizes[type].x, CharacterSpriteSizes[type].y));
        else
            sprite.setTextureRect(sf::IntRect(0, 0, CharacterSpriteSizes[type].x, CharacterSpriteSizes[type].y));

        speed = { -dir.x * ENEMY_SPEED * delta , -dir.y * ENEMY_SPEED * delta };
    }
}