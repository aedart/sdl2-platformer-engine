#ifndef OBJECTS_REGISTRAR_H
#define OBJECTS_REGISTRAR_H

#include <string>

#include "Objects/ObjectsFactory.h"

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
        explicit Registrar(const std::string& identifier);
};

#endif  // OBJECTS_REGISTRAR_H
