#pragma once

struct AnimationComponent
{
    float timer;
    int   index;

    AnimationComponent() 
        : timer(0), index(0) { }
    virtual void UpdateAnimation(float delta) = 0;
};