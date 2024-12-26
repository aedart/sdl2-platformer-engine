#include "Maps/TitleLayer.h"

TitleLayer::TitleLayer(
    const int tileSize,
    const int rows,
    const int columns,
    TileMap& tileMap,
    TilesetList& tilesets
):
    tileSize(tileSize),
    rows(rows),
    columns(columns),
    tileMap(tileMap),
    tilesets(tilesets)
{
}

void TitleLayer::render()
{
    // TODO:
}

void TitleLayer::update(float delta)
{
    // TODO:
}

TileMap& TitleLayer::getTileMap() const
{
    return this->tileMap;
}
