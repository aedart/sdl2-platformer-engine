#ifndef STATES_GAME_STATE_H
#define STATES_GAME_STATE_H

/**
 * Game State
 *
 * @abstract
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class GameState
{
    public:
        /**
         * Initialise this state
         *
         * @return
         */
        virtual bool init() = 0;

        /**
         * Exit this state
         */
        virtual void exit() = 0;

        /**
         * Update this state
         */
        virtual void update() = 0;

        /**
         * Render this state
         */
        virtual void render() = 0;
};

#endif // STATES_GAME_STATE_H
