#include "Graphics/TextureRenderProperties.h"

#include "Cameras/Camera.h"

SDL_Rect TextureRenderProperties::getSource() const
{
    const auto frame = this->column;

    // The source of the texture we wish to draw (row and column / frame)
    return {
        .x = this->width * frame,
        .y = this->height * this->row,
        .w = this->width,
        .h = this->height
    };
}

SDL_Rect TextureRenderProperties::getDestination() const
{
    // Obtain the camera's position, such that the destination of the texture can
    // be drawn correctly, with respect to what the camera's is viewing.
    // Also, add a scrolling ratio to the camara's position to enable parallax scrolling
    // of backgrounds or other elements.
    const auto cameraPosition = Camera::getInstance().getPosition() * scrollRatio;

    // const SDL_Rect dest = {x, y, width, height}; // Original without camera...

    return {
        .x = static_cast<int>(this->x - cameraPosition.x),
        .y = static_cast<int>(this->y - cameraPosition.y),
        .w = static_cast<int>(this->width * this->scaleX),
        .h = static_cast<int>(this->height * this->scaleY),
    };
}
