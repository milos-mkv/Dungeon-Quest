#include "LoadingScreen.h"

#include "Assets.h"
#include "Defines.h"
#include "Game.h"
#include <iostream>

LoadingScreen::LoadingScreen()
{
    try {
        Assets::LoadAssets();
    }
    catch (Exception e) {
        std::cout << e.what() << std::endl;
    }
}

LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::Render(float delta)
{
    //std::cout << delta << std::endl;
}
