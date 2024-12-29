#ifndef MAPS_TITLE_LAYER_H
#define MAPS_TITLE_LAYER_H

#include <vector>

#include "Maps/Layer.h"
#include "Maps/Tileset.h"

/**
 * Tileset List
 */
using TilesetList = std::vector<Tileset*>;

/**
 * Tile Map
 */
using TileMap =
    std::vector<std::vector<int> >;  // NOTE: Additional space important here
                                     // (not sure why...)!

/**
 * Tile Layer
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class TileLayer : public Layer
{
    public:
        /**
         * Constructor
         *
         * @param tileWidth Width of the tiles in this layer, in pixels
         * @param tileHeight Height of the tiles in this layer, in pixels
         * @param rows Amount of rows in tileset
         * @param columns Amount of columns in tileset
         * @param tileMap The tile map matrix
         * @param tilesets List of tilesets
         */
        TileLayer(
            int tileWidth,
            int tileHeight,
            int rows,
            int columns,
            TileMap tileMap,
            TilesetList tilesets
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
        [[nodiscard]] TileMap getTileMap() const;

        /**
         * Get this layers list of tilesets
         *
         * @return
         */
        [[nodiscard]] TilesetList getTilesetsList() const;

        /**
         * Get the tile width in pixels
         *
         * @return
         */
        [[nodiscard]] int getTileWidth() const;

        /**
         * Get the tile height in pixels
         *
         * @return
         */
        [[nodiscard]] int getTileHeight() const;

        /**
         * Get the amount of rows in this layer
         *
         * @return
         */
        [[nodiscard]] int getRows() const;

        /**
         * Get the amount of columns in this layer
         *
         * @return
         */
        [[nodiscard]] int getColumns() const;

    protected:
        /**
         * Width of the tiles in this layer, in pixels
         */
        int tileWidth;

        /**
         * Height of the tiles in this layer, in pixels
         */
        int tileHeight;

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
        TileMap tileMap;

        /**
         * The tilesets in this layer
         */
        TilesetList tilesets;
};

#endif  // MAPS_TITLE_LAYER_H
