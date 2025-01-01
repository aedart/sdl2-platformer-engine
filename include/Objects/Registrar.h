#ifndef OBJECTS_REGISTRAR_H
#define OBJECTS_REGISTRAR_H

#include <string>

#include "Objects/ObjectsFactory.h"
#include "Objects/GameObject.h"
#include "Objects/Properties.h"

/**
 * Objects Registrar
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
template <class T>
class Registrar
{
    public:
        /**
         * Constructor
         *
         * @param identifier
         */
        explicit Registrar(std::string identifier)
        {
            ObjectsFactory::getInstance().bind(identifier, [](Properties* properties)->GameObject* {
                return new T(properties);
            });
        }
};

#endif  // OBJECTS_REGISTRAR_H
