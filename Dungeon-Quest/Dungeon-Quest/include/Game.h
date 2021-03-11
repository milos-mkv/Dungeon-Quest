#pragma once


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Defines.h"
#include "Screen.h"

struct Game
{
    static inline PTR<sf::RenderWindow> window;
    static inline PTR<Screen> screen;

    Game();
    void Run();

private:
    void PollEvents();
};

