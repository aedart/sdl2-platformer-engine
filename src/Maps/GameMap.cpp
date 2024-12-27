#include "Maps/GameMap.h"

#include <vector>

GameMap::GameMap() = default;

void GameMap::update(const float delta) const
{
    for (const auto &layer : this->getLayers()) {
        layer->update(delta);
    }
}

void GameMap::render() const
{
    for (const auto &layer : this->getLayers()) {
        layer->render();
    }
}

std::vector<Layer*>& GameMap::getLayers() const
{
    return *this->layers;
}
