#pragma once


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <Defines.h>
#include <screens/Screen.hpp>

struct Game
{
    static inline PTR<sf::RenderWindow> window;
    static inline PTR<IScreen> screen;

    Game();
    void Run();

private:
    void PollEvents();
};

