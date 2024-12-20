#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H

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

        // TODO:
        void init();

        // TODO:
        void update();

        // TODO:
        void render();

        // TODO:
        void event();

    protected:
        /**
         * Default Constructor
         */
        Engine();

    private:
        /**
         * Singleton instance
         */
        inline static Engine* instance = nullptr;
};

#endif  // CORE_ENGINE_H
