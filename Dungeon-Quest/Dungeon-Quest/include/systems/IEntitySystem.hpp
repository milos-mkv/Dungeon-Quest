#pragma once

struct IEntitySystem
{
    virtual void Update(float delta) = 0;
    virtual ~IEntitySystem() = default;
};