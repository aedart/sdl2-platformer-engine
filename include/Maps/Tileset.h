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
         * ID of the first tile
         */
        int firstID;

        /**
         * ID of the last tile
         */
        int lastID;

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
         * The pixel size of the tiles
         */
        int tileSize;
};

#endif  // MAPS_TILESET_H
