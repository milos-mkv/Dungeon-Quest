#include <Camera.h>

Camera::Camera(float x, float y, float width, float height)
    : sf::View(sf::FloatRect(x, y, width, height)) 
{  
}