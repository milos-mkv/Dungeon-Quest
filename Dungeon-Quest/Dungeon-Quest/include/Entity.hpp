#pragma once

#include <typeindex>
#include <map>
#include <memory>
#include <components/Component.hpp>

struct Entity
{
    std::map<std::type_index, std::shared_ptr<IComponent>> components;

    Entity() = default;

    template<class TComponent> 
    std::shared_ptr<TComponent> GetComponent()
    {
        return std::dynamic_pointer_cast<TComponent>(components[typeid(TComponent)]);
    }
};
