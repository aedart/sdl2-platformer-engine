#include "Maps/Parser.h"

#include <tinyxml2.h>

#include <map>
#include <string>

#include "Maps/GameMap.h"
#include "Maps/TitleLayer.h"

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

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Parser::Parser() = default;