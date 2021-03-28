#pragma once

#include <screens/Screen.hpp>

struct LoadingScreen : public IScreen
{
    LoadingScreen();
    void Render(float delta) override;
    virtual ~LoadingScreen() = default;
};

