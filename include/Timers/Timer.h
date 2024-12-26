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

    protected:

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

#endif // TIMERS_TIMER_H
