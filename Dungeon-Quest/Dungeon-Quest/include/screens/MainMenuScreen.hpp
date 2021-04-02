#pragma once

#include <screens/Screen.hpp>

struct MainMenuScreen final : public IScreen
{
    explicit MainMenuScreen();
    void Render(float delta) override;
};