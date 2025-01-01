#ifndef OBJECTS_OBJECTS_FACTORY_H
#define OBJECTS_OBJECTS_FACTORY_H

#include <functional>
#include <map>
#include <string>

#include "Objects/GameObject.h"
#include "Objects/Properties.h"

/**
 * Objects Factory
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class ObjectsFactory
{
    public:
        /**
         * Prevent copy constructor
         */
        ObjectsFactory(const ObjectsFactory&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        ObjectsFactory& operator=(const ObjectsFactory&) = delete;

        /**
         * Get singleton instance of this factory
         *
         * @return
         */
        static ObjectsFactory& getInstance();

        /**
         * Destroy the objects factory instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~ObjectsFactory();

        /**
         * Bind (register) a game object factory callback to given identifier
         *
         * @param identifier Unique identifier
         * @param callback  Game object factory callback
         */
        void bind(const std::string& identifier,
            const std::function<GameObject*(Properties* properties)>& callback);

        /**
         * Returns a new game object that matches given identifier
         *
         * @param identifier Unique identifier
         * @param properties Game object properties
         *
         * @return New game object
         */
        GameObject* make(const std::string& identifier, Properties* properties);

    protected:
        /**
         * Registry og game object factory callbacks
         */
        std::map<std::string, std::function<GameObject*(Properties* properties)>> registry;

        /**
         * Default constructor
         */
        ObjectsFactory();

    private:
        /**
         * Singleton instance
         */
        inline static ObjectsFactory* instance = nullptr;
};

#endif  // OBJECTS_OBJECTS_FACTORY_H
