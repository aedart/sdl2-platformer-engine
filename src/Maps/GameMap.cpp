#include "Maps/GameMap.h"

#include <vector>

GameMap::GameMap() = default;

void GameMap::update(const float delta) const
{
    for (const auto layer : this->layers) {
        layer->update(delta);
    }
}

void GameMap::render() const
{
    for (const auto layer : this->layers) {
        layer->render();
    }
}
