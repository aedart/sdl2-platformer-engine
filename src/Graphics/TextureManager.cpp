#include "Graphics/TextureManager.h"

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

TextureManager::TextureManager() {}
