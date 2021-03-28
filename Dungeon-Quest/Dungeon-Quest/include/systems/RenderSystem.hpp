#pragma once

#include <systems/IEntitySystem.hpp>
#include <vector>
#include <Entity.hpp>
#include <Defines.h>
#include <Level.hpp>

struct RenderSystem final : public IEntitySystem
{
    PTR<Level> level;

    explicit RenderSystem(const PTR<Level>& level);
    void Update(float delta) override;
};