#include <screens/MainMenuScreen.hpp>
#include <Game.h>
#include <Assets.h>
#include <SFML/Graphics.hpp>

static sf::Sprite title;

MainMenuScreen::MainMenuScreen()
{
    title.setTexture(Assets::GameTitleTexture);
    title.setPosition(Game::window->getSize().x / 2.F - Assets::GameTitleTexture.getSize().x / 2.F, 
        Game::window->getSize().y / 2.F - Assets::GameTitleTexture.getSize().y / 2.F);
}

void MainMenuScreen::Render(float delta)
{
    Game::window->draw(title);
}
