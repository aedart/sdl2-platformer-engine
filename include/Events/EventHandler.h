#ifndef EVENTS_EVENTHANDLER_H
#define EVENTS_EVENTHANDLER_H

/**
 * Event Handler
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class EventHandler
{
    public:
        /**
         * Prevent copy constructor
         */
        EventHandler(const EventHandler&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        EventHandler& operator=(const EventHandler&) = delete;

        /**
         * Get singleton instance of this event handler
         *
         * @return
         */
        static EventHandler& getInstance();

        /**
         * Destroy the event handler instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~EventHandler();

    protected:
        /**
         * Default constructor
         */
        EventHandler();

    private:
        /**
         * Singleton instance
         */
        inline static EventHandler* instance = nullptr;
};

#endif  // EVENTS_EVENTHANDLER_H
