#pragma once

#include <components/Component.hpp>

struct CoinComponent : public IComponent
{
    sf::Vector2f target;
    explicit CoinComponent(const sf::Vector2f& target)
        : target(target) { }
};