#pragma once

#include <exception>
#include <string>

#define PTR std::shared_ptr
#define CreatePTR std::make_shared

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

#define HERO_TYPE_COUNT  3
#define SPRITE_ANIM_NUM  4
#define HERO_STATE_COUNT 3
#define SCALE_FACTOR     10