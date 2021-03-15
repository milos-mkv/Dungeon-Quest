#include <components/CharacterComponent.h>
#include <Assets.h>
#include <Game.h>
#include <cmath>

static sf::Vector2f GetVectorDiff(const sf::Vector2f& collider, const sf::Vector2f& texture)
{
    return sf::Vector2f(std::abs(collider.x - texture.x), std::abs(collider.y - texture.y));
}

CharacterComponent::CharacterComponent(CharacterType type, float x, float y)
    : type(type), state(CharacterState::IDLE)
{
    setPosition({ x, y });                                          // Setting collider position.
    setSize(CharacterColliderSizes[type]);                          // Setting collider size.
    sf::Vector2f diff = GetVectorDiff(CharacterColliderSizes[type], CharacterSpriteSizes[type]);
    sprite.setPosition({ x - diff.x, y - diff.y });                 // Setting sprite position.
    sprite.setTexture(Assets::CharacterTextures[type][state][0]);   // Setting texture for character.
}

void CharacterComponent::UpdateAnimation(float delta)
{
    if ((timer += delta) >= 0.1f)
    {
        sprite.setTexture(Assets::CharacterTextures[type][state][index]);
        index = (index + 1) % 4;
        timer = 0;
    }
}

void CharacterComponent::Draw()
{
    Game::window->draw(sprite); // Draw character sprite.
    Game::window->draw(*this);  // Draw character collider box.
}
