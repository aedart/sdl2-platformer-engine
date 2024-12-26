#ifndef MAPS_LAYER_H
#define MAPS_LAYER_H

/**
 * Map Layer
 *
 * @abstract
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Layer
{
    public:

        /**
         * Render this layer
         */
        virtual void render() = 0;

        /**
         * Update this layer
         *
         * @param delta
         */
        virtual void update(float delta) = 0;
};

#endif  // MAPS_LAYER_H
