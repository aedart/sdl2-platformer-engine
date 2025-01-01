#include "Objects/Registrar.h"

#include "Objects/ObjectsFactory.h"
#include "Objects/GameObject.h"
#include "Objects/Properties.h"

template <class T>
Registrar<T>::Registrar(const std::string& identifier)
{
    ObjectsFactory::getInstance().bind(identifier, [](Properties* properties)->GameObject* {
        return new T(properties);
    });
}
