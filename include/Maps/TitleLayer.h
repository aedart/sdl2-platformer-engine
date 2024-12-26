#ifndef MAPS_TITLE_LAYER_H
#define MAPS_TITLE_LAYER_H

#include <vector>

#include "Maps/Layer.h"
#include "Maps/Tileset.h"

/**
 * Tileset List
 */
using TilesetList = std::vector<Tileset>;

/**
 * Tile Map
 */
using TileMap =
    std::vector<std::vector<int> >;  // NOTE: Additional space important here
                                     // (not sure why...)!

/**
 * Title Layer
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class TitleLayer : public Layer
{
    public:
        /**
         * Constructor
         *
         * @param tileSize The size of the tiles in pixels
         * @param rows Amount of rows in tileset
         * @param columns Amount of columns in tileset
         * @param tileMap The tile map matrix
         * @param tilesets List of tilesets
         */
        TitleLayer(
            int tileSize,
            int rows,
            int columns,
            TileMap& tileMap,
            TilesetList& tilesets
        );

        /**
         * Render this layer
         */
        virtual void render();

        /**
         * Update this layer
         *
         * @param delta
         */
        virtual void update(float delta);

        /**
         * Get this layer's tile map matrix
         *
         * @return
         */
        [[nodiscard]] TileMap& getTileMap() const;

    protected:
        /**
         * The pixel size of the tiles
         */
        int tileSize;

        /**
         * Amount of rows in tileset
         */
        int rows;

        /**
         * Amount of columns in tileset
         */
        int columns;

        /**
         * The tile map matrix
         */
        TileMap& tileMap;

        /**
         * The tilesets in this layer
         */
        TilesetList& tilesets;
};

#endif  // MAPS_TITLE_LAYER_H
