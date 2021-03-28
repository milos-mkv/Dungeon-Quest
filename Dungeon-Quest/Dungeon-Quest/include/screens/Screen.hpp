#pragma once

struct IScreen
{
    virtual void Render(float delta) = 0;
    virtual ~IScreen() = default;
};

