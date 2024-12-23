#ifndef GRAPHICS_TEXTURE_MANAGER_H
#define GRAPHICS_TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

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
         * Clean all textures from the memory
         */
        void clean();

        /**
         * Draw a texture
         *
         * @param id The id of the texture
         * @param x X-axis offset in pixels
         * @param y Y-axis offset in pixels
         * @param width The width of the texture to be drawn in pixels
         * @param height The height of the texture to be drawn in pixels
         * @param flip Flip mode
         */
        void draw(
            const std::string& id,
            int x,
            int y,
            int width,
            int height,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );

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
