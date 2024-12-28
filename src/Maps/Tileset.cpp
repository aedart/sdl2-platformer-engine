#include "Maps/Tileset.h"

#include <string>
#include <iostream>
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

void Tileset::print(const std::string& message) const
{
    std::cout << "Tileset: " << std::endl
        << message << ": " << std::endl
        << "name: " << this->name << std::endl
        << "source: " << this->source << std::endl
        << "tile width: " << this->tileWidth << std::endl
        << "tile height: " << this->tileHeight << std::endl
        << "rows: " << this->rows << std::endl
        << "columns: " << this->columns << std::endl
        << "tiles count: " << this->tilesCount << std::endl
        << "first ID: " << this->firstID << std::endl
        << "last ID: " << this->lastID << std::endl
        << std::endl;
}
