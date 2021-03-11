#pragma once

#include "Screen.h"

struct LoadingScreen : public Screen
{
    LoadingScreen();
   ~LoadingScreen();
    void Render(float delta) override;
};

