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
         * Constructor
         */
        GameMap();

        /**
         * Update this game map
         *
         * @param delta
         */
        void update(float delta);

        /**
         * Render this game map
         */
        void render();

        /**
         * Get the layers of this game map
         *
         * @return
         */
        std::vector<Layer*>& getLayers() const;

    protected:
        /**
         * Layers of this map
         */
        std::vector<Layer*>* layers;
};

#endif  // MAPS_GAME_MAP_H
