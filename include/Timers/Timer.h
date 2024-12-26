#ifndef TIMERS_TIMER_H
#define TIMERS_TIMER_H

/**
 * Timer
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Timer
{
    public:
        /**
         * Default targeted frames per second
         */
        static constexpr int DEFAULT_TARGET_FPS = 60;

        /**
         * Default targeted delta time (in milliseconds)
         */
        static constexpr float DEFAULT_TARGET_DELTA_TIME = 1.5f;

        /**
         * Prevent copy constructor
         */
        Timer(const Timer&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        Timer& operator=(const Timer&) = delete;

        /**
         * Get singleton instance of this timer
         *
         * @return
         */
        static Timer& getInstance();

        /**
         * Destroy the timer instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~Timer();

        /**
         * Computes the delta time
         */
        void tick();

        /**
         * Returns the time past since last tick
         *
         * @return Delta time in milliseconds
         */
        [[nodiscard]] float getDeltaTime() const;

        /**
         * Get the time of the last tick
         *
         * @return
         */
        [[nodiscard]] float getLastTime() const;

        /**
         * Set the targeted frames per second
         *
         * @param fps
         */
        void setTargetFPS(int fps);

        /**
         * Get the targeted frames per second
         *
         * @return
         */
        [[nodiscard]] int getTargetFPS() const;

        /**
         * Set the targeted delta time
         *
         * @param deltaTime Time in milliseconds
         */
        void setTargetDeltaTime(float deltaTime);

        /**
         * Get the targeted delta time
         *
         * @return Target delta time in milliseconds
         */
        [[nodiscard]] float getTargetDeltaTime() const;

    protected:
        /**
         * The past between two ticks, in milliseconds
         */
        float deltaTime;

        /**
         * Time of last tick
         */
        float lastTime;

        /**
         * The targeted frames per second
         */
        int targetFps;

        /**
         * The targeted delta time, in milliseconds
         */
        float targetDeltaTime;

        /**
         * Default constructor
         */
        Timer();

    private:
        /**
         * Singleton instance
         */
        inline static Timer* instance = nullptr;
};

#endif  // TIMERS_TIMER_H
