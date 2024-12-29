#ifndef COLLISIONS_COLLISION_HANDLER_H
#define COLLISIONS_COLLISION_HANDLER_H

/**
 * Collision Handler
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class CollisionHandler
{
    public:
        /**
         * Prevent copy constructor
         */
        CollisionHandler(const CollisionHandler&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        CollisionHandler& operator=(const CollisionHandler&) = delete;

        /**
         * Get singleton instance of this handler
         *
         * @return
         */
        static CollisionHandler& getInstance();

        /**
         * Destroy the collision handler instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~CollisionHandler();

    protected:

        /**
         * Default constructor
         */
        CollisionHandler();

    private:
        /**
         * Singleton instance
         */
        inline static CollisionHandler* instance = nullptr;
};

#endif // COLLISIONS_COLLISION_HANDLER_H
