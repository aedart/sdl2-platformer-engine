#include "Maps/Parser.h"

#include <SDL2/SDL.h>
#include <tinyxml2.h>

#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <iostream>

#include "Maps/GameMap.h"
#include "Maps/TitleLayer.h"
#include "Maps/Tileset.h"

Parser& Parser::getInstance()
{
    if (instance == nullptr) {
        instance = new Parser();
    }

    return *instance;
}

void Parser::destroy()
{
    delete instance;
}

Parser::~Parser()
{
    if (!this->maps.empty()) {
        this->clean();
    }

    instance = nullptr;
}

bool Parser::load(const std::string& id, const std::string& source)
{
    return this->parse(id, source);
}

bool Parser::has(const std::string& id) const
{
    return this->maps.contains(id);
}

GameMap* Parser::get(const std::string& id)
{
    return this->maps[id];
}

void Parser::clean()
{
    std::map<std::string, GameMap*>::iterator iterator;
    for (iterator = this->maps.begin(); iterator != this->maps.end(); iterator++) {
        delete iterator->second;
    }

    this->maps.clear();
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Parser::Parser() = default;

bool Parser::parse(const std::string& id, const std::string& source)
{
    tinyxml2::XMLDocument document;

    // Attempt to load the source xml document.
    document.LoadFile(source.c_str());
    if (document.Error()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load map (ID %s): %s", id.c_str(), document.ErrorStr());
        return false;
    }

    // Obtain the root element (<map> element)
    const tinyxml2::XMLElement* root = document.RootElement();
    if (root == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Map (ID %s) is empty: %s", id.c_str(), source.c_str());
        return false;
    }

    const int rows = root->IntAttribute("height");
    const int columns = root->IntAttribute("width");
    const int tileWidth = root->IntAttribute("tilewidth");
    const int tileHeight = root->IntAttribute("tileheight");

    // Parse tilesets and layers
    //const auto tilesetList = new TilesetList();
    TilesetList tilesetList;
    const auto gameMap = new GameMap();
    for (const tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
        // Cast node's name to string for comparison...
        const std::string node = element->Name();

        // Parse <tileset> element
        if (node == "tileset") {
            // Parse data into a new tileset instance, abort if something went wrong.
            auto tileset = this->parseTileset(element);
            if (tileset == nullptr) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to process tileset for map (ID %s)", id.c_str());
                return false;
            }

            tilesetList.push_back(tileset);
            continue;
        }

        // Parse <layer> element
        if (node == "layer") {
            auto tileLayer = this->parseTitleLayer(element, tilesetList, tileWidth, tileHeight, rows, columns);
            if (tileLayer == nullptr) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to process layer for map (ID %s)", id.c_str());
                return false;
            }

            gameMap->layers.push_back(tileLayer);
        }
    }

    // Abort if the game map does not have any layers
    if (gameMap->layers.empty()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to process any layers for map (ID %s)", id.c_str());
        return false;
    }

    // Finally, store reference to the loaded map
    this->maps[id] = gameMap;

    return true;
}

Tileset* Parser::parseTileset(const tinyxml2::XMLElement* element)
{
    // Obtain values from element
    const std::string name = element->Attribute("name");

    auto sourceElement = element->FirstChildElement("image");
    if (sourceElement == nullptr) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Tileset %s has not source image", name.c_str());
        return nullptr;
    }

    const std::string source = sourceElement->Attribute("source");

    const int tileWidth = element->IntAttribute("tilewidth");
    const int tileHeight = element->IntAttribute("tileheight");

    const int columns = element->IntAttribute("columns");
    const int tilesCount = element->IntAttribute("tilecount");
    const int rows = tilesCount / columns;

    const int firstID = element->IntAttribute("firstgid");
    const int lastID = (firstID + tilesCount) - 1;

    // Populate new tileset
    return new Tileset(
        name,
        source,
        tileWidth,
        tileHeight,
        rows,
        columns,
        tilesCount,
        firstID,
        lastID
    );
}

TitleLayer* Parser::parseTitleLayer(
    const tinyxml2::XMLElement* element,
    const TilesetList& tilesets,
    const int tileWidth,
    const int tileHeight,
    const int rows,
    const int columns
)
{
    const tinyxml2::XMLElement* data = element->FirstChildElement("data");

    // Obtain the layer's matrix (in csv format)
    const std::string matrix = data->GetText();

    // Create string stream buffer for the matrix.
    std::istringstream buffer(matrix);

    // The "input" to be populated from the buffer.
    std::string input;

    // Make a new 2D array (vector) for the tilemap
    //const auto tilemap = new TileMap(rows, std::vector(columns, 0));
    TileMap tilemap(rows, std::vector(columns, 0));

    // Loop through the matrix according to amount of rows and columns,
    // and populate the tilemap vector.
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            std::getline(buffer, input, ',');

            tilemap[row][column] = std::stoi(input);

            // Abort in case stream is no longer valid.
            if (!buffer.good()) {
                break;
            }
        }
    }

    // Finally, return a new Tile Layer instance
    return new TitleLayer(
        tileWidth,
        tileHeight,
        rows,
        columns,
        tilemap,
        tilesets
    );
}