#include "Game.h"

#include "LoadingScreen.h"
#include "GameplayScreen.h"

Game::Game()
{
    if (window != NULL)
        return;
    window = CreatePTR<sf::RenderWindow>(sf::VideoMode().getDesktopMode(), "Dungeon Quest!", sf::Style::None);
    window->setMouseCursorVisible(false);
    window->setVerticalSyncEnabled(true);

    screen = CreatePTR<LoadingScreen>();
    screen = CreatePTR<GameplayScreen>();

}

void Game::Run()
{
    sf::Clock clock;
    while (window->isOpen())
    {
        float delta = clock.restart().asSeconds();
        PollEvents();
        window->clear(sf::Color::Black);
        screen->Render(delta);
        window->display();
    }
}

void Game::PollEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.key.code == sf::Keyboard::Escape)
            window->close();
    }
}

