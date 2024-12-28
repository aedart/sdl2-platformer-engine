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
    this->clean();

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
    // Skip if there is nothing to clean...
    if (this->textures.empty()) {
        return;
    }

    std::map<std::string, SDL_Texture*>::iterator iterator;

    for (iterator = this->textures.begin(); iterator != this->textures.end(); iterator++) {
        this->destroyTexture(iterator->second);
    }

    this->textures.clear();
}

void TextureManager::draw(
    const std::string& id,
    const int x,
    const int y,
    const int width,
    const int height,
    const SDL_RendererFlip flip
){
    this->drawFrame(
        id,
        x,
        y,
        width,
        height,
        0,
        0,
        flip
    );
}

void TextureManager::drawFrame(
    const std::string& id,
    const int x,
    const int y,
    const int width,
    const int height,
    const int row,
    const int frame,
    const SDL_RendererFlip flip
) {
    // Abort if no texture exists for given id
    if (!this->textures.contains(id)) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to find texture for id: %s", id.c_str());
        return;
    }

    // The source of the texture we wish to draw (row and frame)
    const SDL_Rect source = {width * frame, height * row, width, height};

    // The destination on screen where the texture must be drawn
    const SDL_Rect dest = {x, y, width, height};

    const auto success = SDL_RenderCopyEx(
        Engine::getInstance().getRenderer(),
        this->textures[id],
        &source,
        &dest,
        0,
        nullptr,
        flip
    );

    if (success != 0) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to render texture for %s: %s", id.c_str(), SDL_GetError());
    }
}

void TextureManager::drawTile(
    const std::string& tilesetID,
    const int x,
    const int y,
    const int width,
    const int height,
    const int row,
    const int frame,
    const SDL_RendererFlip flip
) {
    this->drawFrame(
        tilesetID,
        x,
        y,
        width,
        height,
        row,
        frame,
        flip
    );
}

void TextureManager::drop(const std::string& id)
{
    // Abort if no texture exists for given id
    if (!this->textures.contains(id)) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to destroy texture for id: %s", id.c_str());
        return;
    }

    this->destroyTexture(this->textures[id]);

    this->textures.erase(id);
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

TextureManager::TextureManager() = default;

void TextureManager::destroyTexture(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}
