#pragma once

/*!
 * Animation Component is used for defining change timer of sprite that is animatable.
 */
struct AnimationComponent
{
    float timer;    // Change timer of image.
    int   index;    // Index of current image.

    AnimationComponent() : timer(0), index(0) { }   // Default constructor.
    virtual void UpdateAnimation(float delta) = 0;  // To be implemented.
};