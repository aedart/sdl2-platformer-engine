#include "Maps/GameMap.h"
#include "Maps/Layer.h"

#include <iostream>
#include <vector>

GameMap::GameMap() = default;

GameMap::~GameMap()
{
    for (const auto &layer: this->layers) {
        delete layer;
    }
    this->layers.clear();
}

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
