#include <components/CharacterComponent.h>
#include <Assets.h>
#include <Game.h>
#include <cmath>

static sf::Vector2f GetVectorDiff(const sf::Vector2f& collider, const sf::Vector2f& texture)
{
    return sf::Vector2f(std::abs(collider.x - texture.x), std::abs(collider.y - texture.y));
}

CharacterComponent::CharacterComponent(CharacterType type, float x, float y)
    : type(type), state(CharacterState::IDLE), attackType(CharacterProperties[type].attackType), life(CharacterProperties[type].life)
{
    setPosition({ x, y });                                          // Setting collider position.
    setSize(CharacterProperties[type].colliderSize);                // Setting collider size.
    sf::Vector2f diff = GetVectorDiff(CharacterProperties[type].colliderSize, CharacterProperties[type].spriteSize);
    sprite.setPosition({ x - diff.x / 2, y - diff.y });             // Setting sprite position.
    sprite.setTexture(Assets::CharacterTextures[type][state][0]);   // Setting texture for character.
}

void CharacterComponent::UpdateAnimation(float delta)
{
    if ((timer += delta) >= 0.12f)
    {
        sprite.setTexture(Assets::CharacterTextures[type][state][index]);
        index = (index + 1) % 4;
        timer = 0;
    }
}

void CharacterComponent::Draw()
{
    Game::window->draw(sprite); // Draw character sprite.
#ifdef DEBUG_MODE
    Game::window->draw(*this);  // Draw character collider box.
#endif
}

void CharacterComponent::FlipTexture(bool flip)
{
    if(flip)
        sprite.setTextureRect(sf::IntRect(CharacterProperties[type].spriteSize.x, 0, -CharacterProperties[type].spriteSize.x, CharacterProperties[type].spriteSize.y));
    else
        sprite.setTextureRect(sf::IntRect(0, 0, CharacterProperties[type].spriteSize.x, CharacterProperties[type].spriteSize.y));
}

sf::Vector2f CharacterComponent::GetCenter() const
{
    return  getPosition() + getSize() / 2.f;
}