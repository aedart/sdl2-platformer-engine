#include "Animations/Animation.h"

#include <SDL2/SDL.h>

#include <iostream>
#include <ostream>
#include <string>

#include "Graphics/TextureManager.h"

Animation::Animation() {}

void Animation::update()
{
    // TODO: Take delta into account?

    // Prevent looping animation, if needed.
    if (!this->loop && this->frame == this->lastFrame) {
        this->frame = this->lastFrame;
        return;
    }

    // Otherwise, compute the next frame to be rendered
    this->frame = (SDL_GetTicks() / this->animationSpeed) % this->amountFrames;
}

void Animation::draw(
    const float x,
    const float y,
    const float width,
    const float height,
    const SDL_RendererFlip flip
) const
{
    TextureManager::getInstance().drawFrame(
        this->textureID,
        x,
        y,
        width,
        height,
        this->row,
        this->column + this->frame,
        flip
    );
}

void Animation::setProperties(
    const std::string& textureID,
    const int amountFrames,
    const int animationSpeed,
    const int row,
    const int column,
    const bool loop
) {
    this->textureID = textureID;
    this->amountFrames = amountFrames;
    this->animationSpeed = animationSpeed;
    this->row = row;
    this->column = column;
    this->loop = loop;
    this->lastFrame = this->amountFrames - 1;

    // Debug
    // std::cout << this->textureID << ", total frames: " << this->amountFrames << ", last frame: " << this->lastFrame << std::endl;
}
