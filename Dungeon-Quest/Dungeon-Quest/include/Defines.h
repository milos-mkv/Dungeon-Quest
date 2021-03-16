#pragma once

#include <memory>
#include <string>

#define PTR std::shared_ptr
#define CreatePTR std::make_shared

#define TILE_SIZE       16
#define VIEWPORT_WIDTH  247
#define VIEWPORT_HEIGHT 135

// Hero

#define HERO_SPEED       100

struct Exception : public std::exception
{
    std::string message;
    Exception(const std::string& message) : message(message) { }

    const char* what() const throw()
    {
        return message.c_str();
    }
};

#define ASSERT(expr, message) if(!expr) { throw Exception(message); }

static inline float Map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}
