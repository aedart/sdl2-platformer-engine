#include "Animations/Animation.h"

#include <string>
#include <SDL2/SDL.h>
#include "Graphics/TextureManager.h"

Animation::Animation() {}

void Animation::update()
{
    // TODO: Need to take delta into account.

    this->frame = (SDL_GetTicks() / this->animationSpeed) % this->amountFrames;
}

void Animation::draw(const float x, const float y, const float width, const float height) const
{
    TextureManager::getInstance().drawFrame(
        this->textureID,
        x,
        y,
        width,
        height,
        this->row,
        this->frame,
        this->flip
    );
}

void Animation::setProperties(
    const std::string& textureID,
    const int row,
    const int amountFrames,
    const int animationSpeed,
    const SDL_RendererFlip flip
) {
    this->textureID = textureID;
    this->row = row;
    this->amountFrames = amountFrames;
    this->animationSpeed = animationSpeed;
    this->flip = flip;
}
