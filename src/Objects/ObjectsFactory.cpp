#include "Objects/ObjectsFactory.h"

#include <functional>
#include <string>

#include "Objects/GameObject.h"
#include "Objects/Properties.h"

ObjectsFactory& ObjectsFactory::getInstance()
{
    if (instance == nullptr) {
        instance = new ObjectsFactory();
    }

    return *instance;
}

void ObjectsFactory::destroy()
{
    delete instance;
}

ObjectsFactory::~ObjectsFactory()
{
    instance = nullptr;
}

void ObjectsFactory::bind(
    const std::string& identifier,
    const std::function<GameObject*(Properties* properties)>& callback
)
{
    this->registry[identifier] = callback;
}

GameObject* ObjectsFactory::make(const std::string& identifier, Properties* properties)
{
    GameObject* object = nullptr;

    if (const auto it = this->registry.find(identifier); it != this->registry.end()) {
        object = it->second(properties);
    }

    return object;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

ObjectsFactory::ObjectsFactory() = default;