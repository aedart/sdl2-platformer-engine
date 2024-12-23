#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/**
 * Engine
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Engine
{
    public:
        /**
         * Prevent copy constructor
         */
        Engine(const Engine&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        Engine& operator=(const Engine&) = delete;

        /**
         * Get singleton instance
         *
         * @return
         */
        static Engine& getInstance();

        /**
         * Destructor
         */
        virtual ~Engine();

        /**
         * Destroy the engine instance
         *
         * **Warning**: singleton instance will be rest when
         * this method is invoked
         */
        static void destroy();

        /**
         * Initialise this engine
         *
         * Method creates a new window and changes engine's
         * running state to `true`.
         *
         * @param title Window title
         * @param width Window width in pixels
         * @param height Window height in pixels
         *
         * @return False has already been initialised (if running) or
         *         if underlying drivers failed to initialise.
         */
        bool init(const char* title, int width, int height);

        /**
         * Cleans all elements that are in memory
         *
         * @return
         */
        bool clean();

        /**
         * Stop the engine
         */
        void quit();

        // TODO:
        void update();

        // TODO:
        void render();

        /**
         * Polls the underlying SDL for any events
         * and reacts accordingly.
         */
        void event();

        /**
         * Determine if the engine is running
         *
         * @return
         */
        [[nodiscard]] bool isRunning() const;

        /**
         * Get the SLD renderer
         *
         * @return
         */
        [[nodiscard]] SDL_Renderer* getRenderer() const;

        /**
         * Returns the screen width in pixels
         *
         * @return
         */
        [[nodiscard]] int getScreenWidth() const;

        /**
         * Returns the screen height in pixels
         *
         * @return
         */
        [[nodiscard]] int getScreenHeight() const;

    protected:
        /**
         * Running state of this engine
         */
        bool running;

        /**
         * Screen width in pixels
         */
        int screenWidth;

        /**
         * Screen height in pixels
         */
        int screenHeight;

        /**
         * The window in which the engine will render
         */
        SDL_Window* window;

        /**
         * The SDL renderer
         */
        SDL_Renderer* renderer;

        /**
         * Default Constructor
         */
        Engine();

        /**
         * Returns a new SDL window
         *
         * @param title Window title
         * @param width Window width in pixels
         * @param height Window height in pixels
         *
         * @return
         */
        SDL_Window* makeWindow(const char* title, int width, int height);

        /**
         * Returns a new SDL renderer
         *
         * @param window
         *
         * @return
         */
        SDL_Renderer* makeRenderer(SDL_Window* window);

    private:
        /**
         * Singleton instance
         */
        inline static Engine* instance = nullptr;
};

#endif  // CORE_ENGINE_H
