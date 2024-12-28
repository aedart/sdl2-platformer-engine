#ifndef MAPS_GAME_MAP_H
#define MAPS_GAME_MAP_H

#include <vector>

#include "Maps/Layer.h"

/**
 * Game Map
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class GameMap
{
    public:
        /**
         * Layers of this map
         */
        std::vector<Layer*> layers;

        /**
         * Constructor
         */
        GameMap();

        /**
         * Destructor
         */
        ~GameMap();

        /**
         * Update this game map
         *
         * @param delta
         */
        void update(float delta) const;

        /**
         * Render this game map
         */
        void render() const;
};

#endif  // MAPS_GAME_MAP_H
