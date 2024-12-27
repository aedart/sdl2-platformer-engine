#include "Maps/Tileset.h"

#include <string>
#include <utility>

Tileset::Tileset(
    const std::string& name,
    const std::string& source,
    const int tileWidth,
    const int tileHeight,
    const int rows,
    const int columns,
    const int tilesCount,
    const int firstID,
    const int lastID
):
    name(name),
    source(source),
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    rows(rows),
    columns(columns),
    tilesCount(tilesCount),
    firstID(firstID),
    lastID(lastID)
{
}
