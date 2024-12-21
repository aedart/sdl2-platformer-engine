#ifndef GRAPHICS_TEXTURE_MANAGER_H
#define GRAPHICS_TEXTURE_MANAGER_H

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

    protected:
        /**
         * Default constructor
         */
        TextureManager();

    private:
        /**
         * Singleton instance
         */
        inline static TextureManager* instance = nullptr;
};

#endif  // GRAPHICS_TEXTURE_MANAGER_H
