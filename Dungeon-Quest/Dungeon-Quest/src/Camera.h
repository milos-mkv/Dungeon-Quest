#pragma once

#include <SFML/Graphics.hpp>

struct Camera : public sf::View
{
    Camera(float x, float y, float width, float height);
    void ProcessInput(float delta, float speed);
};

/*
sf::Vector2f GetCursorPos()
    {
        return {
            Map(sf::Mouse::getPosition().x, 0.0f, Window::width,  getCenter().x - size.x / 2, getCenter().x + size.x / 2),
            Map(sf::Mouse::getPosition().y, 0.0f, Window::height, getCenter().y - size.y / 2, getCenter().y + size.y / 2)
        };
    }
*/