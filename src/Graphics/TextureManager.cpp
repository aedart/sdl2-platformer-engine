#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Graphics/TextureManager.h"
#include "Core/Engine.h"

TextureManager& TextureManager::getInstance()
{
    if (instance == nullptr) {
        instance = new TextureManager();
    }

    return *instance;
}

TextureManager::~TextureManager()
{
    instance = nullptr;
}

void TextureManager::destroy()
{
    delete instance;
}

bool TextureManager::load(const std::string& id, const std::string& file)
{
    // Load the surface
    SDL_Surface* surface = IMG_Load(file.c_str());
    if (surface == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture %s: %s", file.c_str(), SDL_GetError());
        return false;
    }

    // Create texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(
        Engine::getInstance().getRenderer(),
        surface
    );
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed create texture from surface, for %s: %s", file.c_str(), SDL_GetError());
        return false;
    }

    // Save reference to texture in map
    this->textures[id] = texture;

    return true;
}

void TextureManager::clean()
{

}

void TextureManager::draw(
    const std::string& id,
    const int x,
    const int y,
    const int width,
    const int height,
    SDL_RendererFlip flip
){
    // Abort if no texture exists for given id
    if (!this->textures.contains(id)) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to find texture for id: %s", id.c_str());
        return;
    }

    // The source of the texture we wish to draw
    const SDL_Rect source = { 0, 0, width, height };

    // The destination on screen where the texture must be drawn
    const SDL_Rect dest = { x, y, width, height };

    const auto success = SDL_RenderCopyEx(
        Engine::getInstance().getRenderer(),
        this->textures[id],
        &source,
        &dest,
        0,
        nullptr,
        flip
    );

    if (!success) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to render texture for %s: %s", id.c_str(), SDL_GetError());
    }
}

void TextureManager::drop(const std::string& id)
{

}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

TextureManager::TextureManager() = default;
