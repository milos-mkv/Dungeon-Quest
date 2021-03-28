#pragma once

#include <memory>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <cmath>

#define DEBUG_MODE

#define PTR       std::shared_ptr
#define CreatePTR std::make_shared

constexpr int TILE_SIZE       = 16;
constexpr int VIEWPORT_WIDTH  = 247 * 2;
constexpr int VIEWPORT_HEIGHT = 135 * 2;

static sf::Vector2f GetVectorDiff(const sf::Vector2f& collider, const sf::Vector2f& texture)
{
    return sf::Vector2f(std::abs(collider.x - texture.x), std::abs(collider.y - texture.y));
}


static sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = std::sqrt((source.x * source.x) + (source.y * source.y));
    return (length != 0) ? sf::Vector2f(source.x / length, source.y / length) : source;
}

struct Exception : public std::exception
{
    std::string message;
    explicit Exception(const std::string& message) : message(message) { }

    const char* what() const throw() override
    {
        return message.c_str();
    }
};

#define ASSERT(expr, message) if(!expr) { throw Exception(message); }

[[nodiscard]]
static inline float Map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

static inline int RandInt(int min, int max) 
{
    return min + (rand() % (max - min + 1));
}

static inline float RandFloat(float min, float max) 
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}