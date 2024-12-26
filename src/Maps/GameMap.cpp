#include "Maps/GameMap.h"

#include <vector>

GameMap::GameMap() = default;

void GameMap::update(const float delta)
{
    for (const auto &layer : this->layers) {
        layer->update(delta);
    }
}

void GameMap::render()
{
    for (const auto &layer : this->layers) {
        layer->render();
    }
}

std::vector<Layer*>& GameMap::getLayers()
{
    return this->layers;
}
