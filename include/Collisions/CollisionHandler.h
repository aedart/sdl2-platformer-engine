#ifndef COLLISIONS_COLLISION_HANDLER_H
#define COLLISIONS_COLLISION_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include "Maps/TileLayer.h"

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

        /**
         * Determine if there is a collision between rect a and b
         *
         * @param a First rect
         * @param b Second rect
         *
         * @return
         */
        bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

        /**
         * Determine if there is a collision between given rect and
         * the map's collision layer
         *
         * @param a The rect to check against
         *
         * @return
         */
        [[nodiscard]] bool mapCollision(const SDL_Rect& a) const;

    protected:
        /**
         * The actual tilemap (matrix) that contains
         * collision tiles.
         */
        TileMap layerTileMap;

        /**
         * The collision layer
         */
        TileLayer* collisionLayer;

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
