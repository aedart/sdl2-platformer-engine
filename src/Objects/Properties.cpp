#include "Objects/Properties.h"

#include <string>
#include <utility>
#include <SDL2/SDL.h>

Properties::Properties(
    std::string textureID,
    const int width,
    const int height,
    const float x,
    const float y,
    const SDL_RendererFlip flip
):
    textureID(std::move(textureID)),
    width(width),
    height(height),
    x(x),
    y(y),
    flip(flip)
{
}
