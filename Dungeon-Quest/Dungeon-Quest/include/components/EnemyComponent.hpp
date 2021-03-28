#pragma once

#include <components/Component.hpp>

struct EnemyComponent : public IComponent
{
    bool chasing = false;
    EnemyComponent() = default;
};

