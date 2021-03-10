#pragma once

#include <memory>
#include <string>

#define PTR std::shared_ptr
#define CreatePTR std::make_shared

#define TILE_SIZE       16
#define VIEWPORT_WIDTH  247
#define VIEWPORT_HEIGHT 135
#define HERO_WIDTH      16
#define HERO_HEIGHT     28
#define HERO_HEIGHT_OFFSET 12

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

/*
#include <exception>
#include <string>

#define PTR std::shared_ptr
#define CreatePTR std::make_shared


#define HERO_TYPE_COUNT  3
#define SPRITE_ANIM_NUM  4
#define HERO_STATE_COUNT 3
#define SCALE_FACTOR     10
#define TILE_SIZE        16


*/