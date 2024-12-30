#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include <tinyxml2.h>

#include "Graphics/TextureManager.h"
#include "Graphics/TextureRenderProperties.h"
#include "Core/Engine.h"
#include "Cameras/Camera.h"

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

bool TextureManager::parseTexture(const std::string& source)
{
    tinyxml2::XMLDocument document;

    // Attempt to load the source xml document.
    document.LoadFile(source.c_str());
    if (document.Error()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture file (ID %s): %s", source.c_str(), document.ErrorStr());
        return false;
    }

    // Obtain the root element (<map> element)
    const tinyxml2::XMLElement* root = document.RootElement();
    if (root == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Texture file is empty: %s", source.c_str());
        return false;
    }

    // Loop through each defined texture and load them.
    for (const tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
        // Cast node's name to string for comparison...
        const std::string node = element->Name();

        if (node == "texture") {
            const std::string id = element->Attribute("id");
            const std::string src = element->Attribute("source");

            this->load(id, src);
        }
    }

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

void TextureManager::draw(const TextureRenderProperties& properties)
{
    this->drawFrame(properties);
}

void TextureManager::drawFrame(const TextureRenderProperties& properties)
{
    // Abort if no texture exists for given id
    if (!this->textures.contains(properties.id)) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to find texture for id: %s", properties.id.c_str());
        return;
    }

    const auto source = properties.getSource();
    const auto destination = properties.getDestination();

    const auto success = SDL_RenderCopyEx(
        Engine::getInstance().getRenderer(),
        this->textures[properties.id],
        &source,
        &destination,
        properties.angle,
        nullptr,
        properties.flip
    );

    if (success != 0) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to render texture for %s: %s", properties.id.c_str(), SDL_GetError());
    }
}

void TextureManager::drawTile(const TextureRenderProperties& properties)
{
    this->drawFrame(properties);
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
