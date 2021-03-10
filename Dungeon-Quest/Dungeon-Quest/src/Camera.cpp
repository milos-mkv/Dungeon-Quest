#include "Camera.h"

Camera::Camera(float x, float y, float width, float height) : sf::View(sf::FloatRect(x, y, width, height))
{
}

void Camera::ProcessInput(float delta, float speed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move({ -speed * delta, 0 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move({ speed * delta, 0 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        move({ 0, -speed * delta });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move({ 0, speed * delta });
    }
}

