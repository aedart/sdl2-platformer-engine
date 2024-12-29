#include "Collisions/CollisionHandler.h"
#include "Maps/TileLayer.h"
#include "Core/Engine.h"

CollisionHandler& CollisionHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new CollisionHandler();
    }

    return *instance;
}

void CollisionHandler::destroy()
{
    delete instance;
}

CollisionHandler::~CollisionHandler()
{
    instance = nullptr;
}

bool CollisionHandler::checkCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    const bool overlapsX = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    const bool overlapsY = (a.y < b.y + b.h) && (a.y + a.h > b.y);

    return overlapsX && overlapsY;
}

bool CollisionHandler::mapCollision(const SDL_Rect& a) const
{
    // TODO: Seriously!!!
    const int tileSize = 32;

    const int width = this->collisionLayer->getTileWidth();
    const int height = this->collisionLayer->getTileHeight();
    const int rows = this->collisionLayer->getRows();
    const int columns = this->collisionLayer->getColumns();

    int leftTile = a.x / width;
    int rightTile = (a.x + a.w) / width;

    int topTile = a.y / height;
    int bottomTile = (a.y + a.h) / height;

    // Limit left tile
    if (leftTile < 0) {
        leftTile = 0;
    }

    // Limit right tile
    if (rightTile > columns) {
        rightTile = columns;
    }

    // Limit top tile
    if (topTile < 0) {
        topTile = 0;
    }

    // Limit bottom tile
    if (bottomTile > rows) {
        bottomTile = rows;
    }

    // Determine if there is a collision
    for (int i = leftTile; i <= rightTile; i++) {
        for (int j = topTile; j <= bottomTile; j++) {

            // A collision is only valid, if the tile ID is not zero!
            if (this->layerTileMap[j][i] > 0) {
                return true;
            }
        }
    }

    return false;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

CollisionHandler::CollisionHandler()
{
    this->collisionLayer = dynamic_cast<TileLayer*>(
        // TODO: This is really poor - we should be able to determine / set
        // TODO: what the collision layer is intended to be, and not just
        // TODO: have a hard-coded value here!
        Engine::getInstance().getCurrentMap()->layers.back()
    );

    this->layerTileMap = this->collisionLayer->getTileMap();
}
