#ifndef OBJECTS_OBJECT_INTERFACE_H
#define OBJECTS_OBJECT_INTERFACE_H

/**
* Object
*
* @interface
*/
class ObjectInterface
{
    public:
        /**
         * Update this object
         *
         * @param delta
         */
        virtual void update(float delta) = 0;

        /**
         * Draw this object
         */
        virtual void draw() = 0;

        /**
         * Clean this object (remove it)
         */
        virtual void clean() = 0;
};

#endif //OBJECTS_OBJECT_INTERFACE_H
