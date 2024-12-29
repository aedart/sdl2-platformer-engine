#include "Maps/TileLayer.h"
#include "Maps/Tileset.h"
#include "Graphics/TextureManager.h"

#include <iostream>
#include <utility>

TileLayer::TileLayer(
    const int tileWidth,
    const int tileHeight,
    const int rows,
    const int columns,
    TileMap tileMap,
    TilesetList tilesets
):
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    rows(rows),
    columns(columns),
    tileMap(std::move(tileMap)),
    tilesets(std::move(tilesets))
{
    // TODO: Uh... this is really ugle! All tileset' textures are loaded here...
    // TODO: This SHOULD be in a method to be invoked only once.
    auto& manager = TextureManager::getInstance();
    for (const auto &tileset : this->getTilesetsList()) {
        manager.load(tileset->name, "resources/maps/" + tileset->source);
    }
}

void TileLayer::render()
{
    auto& manager = TextureManager::getInstance();

    const auto tileMap = this->tileMap;
    const auto tilesetList = this->tilesets;

    for (unsigned int row = 0; row < this->rows; row++) {
        for (unsigned int column = 0; column < this->columns; column++) {
            int tileID = tileMap[row][column];

            // Skip if tile ID is zero (nothing)
            if (tileID == 0) {
                continue;
            }

            // Determine from which tileset the tile ID originates from, when
            // there are more than one tileset available in this layer.
            int tilesetIndex = 0;
            if (tilesetList.size() > 1) {
                // Because of the structure of "tiled" map, we need to re-resolve the tile ID
                // as well as the index of the tileset, or the wrong image / tile will be drawn!
                for (int i = 0; i < tilesetList.size(); i++) {

                    // If tile ID is inside the current tileset...
                    if (tileID >= tilesetList[i]->firstID && tileID <= tilesetList[i]->lastID) {
                        tileID = tileID + tilesetList[i]->tilesCount - tilesetList[i]->lastID;
                        tilesetIndex = i;
                        break;
                    }
                }
            }

            // Obtain identified tileset and compute target tile row and column
            auto tileset = tilesetList[tilesetIndex];
            int tileRow = tileID / tileset->columns;
            int tileColumn = tileID - (tileRow * tileset->columns) - 1;

            // Adjust row and column, if the tile is located on the last column
            // in the tileset, or it will not be obtainable / drawn!
            if (tileID % tileset->columns == 0) {
                tileRow--;
                tileColumn = tileset->columns - 1;
            }

            // Finally, draw the tile...
            manager.drawTile(
                tileset->name,
                column * this->tileWidth, // NOTE: Use layer's tile size here!
                row * this->tileHeight, // NOTE: Use layer's tile size here!
                tileset->tileWidth,
                tileset->tileHeight,
                tileRow,
                tileColumn
            );
        }
    }
}

void TileLayer::update(float delta)
{
    // TODO:

    // Debug
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TileMap TileLayer::getTileMap() const
{
    return this->tileMap;
}

TilesetList TileLayer::getTilesetsList() const
{
    return this->tilesets;
}
