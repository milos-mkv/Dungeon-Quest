#pragma once

#include <components/Component.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Defines.h>

struct ColliderComponent : public IComponent
{
    sf::RectangleShape collider;

    ColliderComponent()
    {
        Setup();
    }

    ColliderComponent( sf::Vector2f position,  sf::Vector2f size)
    {
        collider.setPosition(position);
        collider.setSize(size);
        Setup();
    }

    ColliderComponent(float x, float y, float width, float height)
    {
        collider.setPosition({ x, y - 2 });
        collider.setSize({ abs(width - x) + TILE_SIZE, abs(height - y) + TILE_SIZE });
        Setup();
    }
    sf::Vector2f GetCenter() const
    {
        return  collider.getPosition() + collider.getSize() / 2.0F;
    }
private:
    void Setup()
    {
        collider.setFillColor(sf::Color::Transparent);
        collider.setOutlineColor(sf::Color::Green);
        collider.setOutlineThickness(1.0F);
    }
};
