#pragma once

#include <components/Component.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct SpriteComponent : public IComponent
{
    sf::Sprite sprite;

    SpriteComponent(const sf::Texture& texture, float x, float y)
    {
        sprite.setPosition(x, y);
        sprite.setTexture(texture);
    }
};