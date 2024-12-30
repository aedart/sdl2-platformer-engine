#ifndef ANIMATIONS_ANIMATION_H
#define ANIMATIONS_ANIMATION_H

/**
 * Animation
 *
 * @abstract
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Animation
{
    public:
        /**
         * Constructor
         *
         * @param repeat If true, animation will continue to repeat
         *               once it has completed.
         */
        explicit Animation(bool repeat = true);

        /**
         * Update this animation
         *
         * @param delta
         */
        virtual void update(float delta) = 0;

        /**
         * Set the repeat state of this animation
         *
         * @param repeat True if animation must repeat, false otherwise
         */
        void setRepeat(bool repeat);

        /**
         * Determine if this animation is repeating
         *
         * @return
         */
        [[nodiscard]] bool isRepeating() const;

        /**
         * Determine if this animation has ended
         *
         * @return
         */
        [[nodiscard]] bool isDone() const;

        /**
         * Set the current frame that must be drawn
         *
         * @param frame
         */
        void setCurrentFrame(int frame);

        /**
         * Get the current frame that is being drawn
         *
         * @return
         */
        [[nodiscard]] int getCurrentFrame() const;

    protected:
        /**
         * State that determines if the animation should
         * be repeated once it has completed.
         */
        bool repeat;

        /**
         * State that determines if animation has
         * completed / ended.
         */
        bool done;

        /**
         * The current frame to be drawn
         */
        int currentFrame;
};

#endif  // ANIMATIONS_ANIMATION_H
