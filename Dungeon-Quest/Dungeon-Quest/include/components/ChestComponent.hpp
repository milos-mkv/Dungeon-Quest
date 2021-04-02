#pragma once

#include <components/Component.hpp>

enum ChestType { EMPTY, FULL };

struct ChestComponent : public IComponent
{
    bool opened = false;
    ChestType   type;
    explicit ChestComponent(ChestType type)
        : type(type) { }
};