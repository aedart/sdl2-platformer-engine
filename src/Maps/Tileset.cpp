#include "Maps/Tileset.h"

#include <string>
#include <utility>

Tileset::Tileset(
    std::string name,
    std::string source,
    const int tileWidth,
    const int tileHeight,
    const int rows,
    const int columns,
    const int tilesCount,
    const int firstID,
    const int lastID
):
    name(std::move(name)),
    source(std::move(source)),
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    rows(rows),
    columns(columns),
    tilesCount(tilesCount),
    firstID(firstID),
    lastID(lastID)
{
}
