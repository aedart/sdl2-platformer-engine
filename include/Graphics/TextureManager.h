#ifndef GRAPHICS_TEXTURE_MANAGER_H
#define GRAPHICS_TEXTURE_MANAGER_H

#include <SDL2/SDL.h>

#include <map>
#include <string>

#include "Graphics/TextureRenderProperties.h"

/**
 * TextureManager
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class TextureManager
{
    public:
        /**
         * Prevent copy constructor
         */
        TextureManager(const TextureManager&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        TextureManager& operator=(const TextureManager&) = delete;

        /**
         * Get singleton instance of this manager
         *
         * @return
         */
        static TextureManager& getInstance();

        /**
         * Destructor
         */
        virtual ~TextureManager();

        /**
         * Destroy the texture manager instance
         */
        static void destroy();

        /**
         * Load a texture from the filesystem
         *
         * @param id The id of the texture
         * @param file Path to the texture file
         *
         * @return
         */
        bool load(const std::string& id, const std::string& file);

        /**
         * Parse the given texture file
         *
         * @param source The source of the texture file (xml file)
         *
         * @return
         */
        bool parseTexture( const std::string& source);

        /**
         * Clean all textures from the memory
         */
        void clean();

        /**
         * Draw a texture
         *
         * @ param properties Rendering properties of texture
         */
        void draw(const TextureRenderProperties& properties);

        /**
         * Draw a frame from given texture
         *
         * @param properties Rendering properties of texture (sprite sheet)
         */
        void drawFrame(const TextureRenderProperties& properties);

        /**
         * Draw a tile from given tileset
         *
         * @param properties Rendering properties of texture (sprite sheet)
         */
        void drawTile(const TextureRenderProperties& properties);

        /**
         * Drop (remove) texture from this manager
         *
         * @param id
         */
        void drop(const std::string& id);

    protected:
        /**
         * Map of the loaded textures
         */
        std::map<std::string, SDL_Texture*> textures;

        /**
         * Default constructor
         */
        TextureManager();

        /**
         * Destroy given texture
         *
         * @param texture
         */
        void destroyTexture(SDL_Texture* texture);

    private:
        /**
         * Singleton instance
         */
        inline static TextureManager* instance = nullptr;
};

#endif  // GRAPHICS_TEXTURE_MANAGER_H
