#pragma once

#include <typeindex>
#include <unordered_map>
#include <memory>
#include <systems/IEntitySystem.hpp>

struct Engine
{
    std::unordered_map<std::type_index, std::shared_ptr<IEntitySystem>> systems;

    Engine() = default;

    template<class TEntitySytem>
    void AddSystem(const std::shared_ptr<IEntitySystem>& component)
    {
        systems[typeid(TEntitySytem)] = component;
    }

    template<class TEntitySytem>
    std::shared_ptr<TEntitySytem> GetSystem()
    {
        return std::dynamic_pointer_cast<TEntitySytem>(systems[typeid(TEntitySytem)]);
    }

    void Update(float delta) const
    {
        for (const auto& [key, system] : systems)
        {
            system->Update(delta);
        }
    }
};
