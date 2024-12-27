#ifndef MAPS_TILESET_H
#define MAPS_TILESET_H

#include <string>

/**
 * Tileset
 *
 * Data structure representation of a tileset
 *
 * @see http://www.mapeditor.org/
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Tileset
{
    public:
        /**
         * Name of this tileset
         */
        std::string name;

        /**
         * The source texture file of this tileset
         */
        std::string source;

        /**
         * Width of the tiles in this set, in pixels
         */
        int tileWidth;

        /**
         * Height of the tiles in this set, in pixels
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
         * Total amount of tiles in this tileset
         */
        int tilesCount;

        /**
         * ID of the first tile
         */
        int firstID;

        /**
         * ID of the last tile
         */
        int lastID;

        /**
         * Constructor
         *
         * @param name Name of this tileset
         * @param source The source texture file of this tileset
         * @param tileWidth Width of the tiles in this set, in pixels
         * @param tileHeight Height of the tiles in this set, in pixels
         * @param rows Amount of rows in tileset
         * @param columns Amount of columns in tileset
         * @param tilesCount Total amount of tiles in this tileset
         * @param firstID ID of the first tile
         * @param lastID ID of the last tile
         */
        Tileset(
            std::string name,
            std::string source,
            int tileWidth,
            int tileHeight,
            int rows,
            int columns,
            int tilesCount,
            int firstID,
            int lastID
        );
};

#endif  // MAPS_TILESET_H
