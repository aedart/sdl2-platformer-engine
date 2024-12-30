#ifndef ANIMATIONS_SEQUENCE_ANIMATION_H
#define ANIMATIONS_SEQUENCE_ANIMATION_H

#include <SDL2/SDL.h>

#include <string>
#include <map>

#include "Animations/Animation.h"
#include "Animations/Sequence.h"

/**
 * Sequence Animation
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class SequenceAnimation : public Animation
{
    public:
        /**
         * Constructor
         *
         * @param repeat If true, animation will continue to repeat
         *               once it has completed.
         */
        explicit SequenceAnimation(bool repeat = true);

        /**
         * Update this animation
         *
         * @param delta
         */
        virtual void update(float delta);

        /**
         * Draw the animation
         *
         * @param x X position in sprite
         * @param y Y position in sprite
         * @param scaleX Scale factor for texture x-axis when rendered
         * @param scaleY Scale factor for texture y-axis when rendered
         * @param flip Flip mode
         */
        void draw(
            float x,
            float y,
            float scaleX = 1.0,
            float scaleY = 1.0,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        ) const;

        /**
         * Parse an animation file (xml)
         *
         * @param source
         *
         * @return
         */
        bool parse(const std::string& source);

        /**
         * Set the current sequence
         *
         * @param id Sequence ID
         */
        void setCurrentSequence(const std::string& id);

    protected:

        /**
         * The current sequence
         */
        Sequence sequence;

        /**
         * Map of the animation sequence
         */
        std::map<std::string, Sequence> sequenceMap;
};

#endif  // ANIMATIONS_SEQUENCE_ANIMATION_H
