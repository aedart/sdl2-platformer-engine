#include "Animations/Animation.h"

#include <string>
#include <SDL2/SDL.h>
#include "Graphics/TextureManager.h"

Animation::Animation() {}

void Animation::update()
{
    // TODO: Take delta into account?

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
    const int column
) {
    this->textureID = textureID;
    this->amountFrames = amountFrames;
    this->animationSpeed = animationSpeed;
    this->row = row;
    this->column = column;
}
