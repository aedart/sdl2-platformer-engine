#include "Maps/Parser.h"

#include <SDL2/SDL.h>
#include <tinyxml2.h>

#include <map>
#include <string>
#include <sstream>
#include <vector>

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
    // TODO:
    return;
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
    const auto tilesetList = new TilesetList();
    const auto gameMap = new GameMap();
    for (const tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
        // Parse <tileset> element
        if (element->Name() == "tileset") {
            tilesetList->push_back(this->parseTileset(element));
        }

        // Parse <layer> element
        if (element->Name() == "layer") {
            auto tileLayer = this->parseTitleLayer(element, tilesetList, tileWidth, tileHeight, rows, columns);
            gameMap->getLayers().push_back(&tileLayer);
        }
    }

    // Finally, store reference to the loaded map
    this->maps[id] = gameMap;

    return true;
}

Tileset Parser::parseTileset(const tinyxml2::XMLElement* element)
{
    // Obtain values from element
    const std::string name = element->Attribute("name");
    const std::string source = element->FirstChildElement("image")->Attribute("source");

    const int tileWidth = element->IntAttribute("tilewidth");
    const int tileHeight = element->IntAttribute("tileheight");

    const int columns = element->IntAttribute("columns");
    const int tilesCount = element->IntAttribute("tilecount");
    const int rows = tilesCount / columns;

    const int firstID = element->IntAttribute("firstgid");
    const int lastID = (firstID + tilesCount) - 1;

    // Populate tileset object
    return {
        name,
        source,
        tileWidth,
        tileHeight,
        rows,
        columns,
        tilesCount,
        firstID,
        lastID
    };
}

TitleLayer Parser::parseTitleLayer(
    const tinyxml2::XMLElement* element,
    TilesetList* tilesets,
    const int tileWidth,
    const int tileHeight,
    const int rows,
    const int columns
)
{
    const tinyxml2::XMLElement* data = element->FirstChildElement("data");

    // Obtain the layer's matrix into a string stream.
    const std::string matrix = data->GetText();
    std::istringstream matrixStream(matrix);

    // Make a new 2D array (vector) for the tilemap
    //TileMap tilemap(rows, std::vector<int>(columns, 0));
    auto tilemap = new TileMap(rows, std::vector<int>(columns, 0));

    // The "tile id", which will be used to identify which tile must
    // be rendered (see loop below).
    std::string id;

    // Loop through the matrix according to amount of rows and columns,
    // and populate the tilemap vector.
    for (int row = 0; row == rows; row++) {
        for (int column = 0; column == columns; column++) {
            std::getline(matrixStream, id, ',');

            // const std::stringstream converter(id);
            // converter >> tilemap[row][column];

            int value;
            std::stringstream converter(id);
            converter >> value;

            tilemap[row][column].push_back(value);

            // Abort in case stream is no longer valid.
            if (!matrixStream.good()) {
                break;
            }
        }
    }

    // Finally, return a new Tile Layer instance
    return TitleLayer(
        tileWidth,
        tileHeight,
        rows,
        columns,
        tilemap,
        tilesets
    );
}