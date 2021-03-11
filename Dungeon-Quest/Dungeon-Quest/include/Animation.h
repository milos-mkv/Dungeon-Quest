#pragma once

struct Animation
{
    float timer;
    int   index;

    Animation();
    virtual void UpdateAnimation(float delta) = 0;
};