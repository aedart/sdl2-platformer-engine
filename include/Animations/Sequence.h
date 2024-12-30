#ifndef ANIMATIONS_SEQUENCE_H
#define ANIMATIONS_SEQUENCE_H

#include <vector>
#include <string>

/**
 * Animation Sequence
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
struct Sequence
{
    /**
     * The animation speed
     */
    int speed;

    /**
     * The total amount of frames of this animation
     */
    int frames;

    /**
     * Width of the texture, in pixels
     */
    int width;

    /**
     * Height of the texture, in pixels
     */
    int height;

    /**
     * Ordered list of texture IDs
     */
    std::vector<std::string> textureIDs;
};

#endif  // ANIMATIONS_SEQUENCE_H
