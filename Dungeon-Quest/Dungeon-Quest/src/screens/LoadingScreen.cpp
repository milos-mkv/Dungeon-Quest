#include <screens/LoadingScreen.h>

#include <Assets.h>
#include <Defines.h>
#include <Game.h>
#include <iostream>

LoadingScreen::LoadingScreen()
{
    try {
        Assets::LoadAssets();
    }
    catch (const Exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void LoadingScreen::Render(float delta)
{
    /* Shit */
}
