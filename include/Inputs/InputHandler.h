#ifndef INPUTS_INPUT_HANDLER_H
#define INPUTS_INPUT_HANDLER_H

#include <SDL2/SDL.h>

/**
 * Input Handler
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class InputHandler
{
    public:
        /**
         * Prevent copy constructor
         */
        InputHandler(const InputHandler&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        InputHandler& operator=(const InputHandler&) = delete;

        /**
         * Get singleton instance of this input handler
         *
         * @return
         */
        static InputHandler& getInstance();

        /**
         * Destroy the input handler instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~InputHandler();

        /**
         * Listen for input events
         */
        void listen();

        /**
         * Determine if a key is down
         *
         * @param key The SDL code representation of input key
         *
         * @return
         */
        [[nodiscard]] bool isKeyDown(SDL_Scancode key) const;

    protected:
        /**
         * Stores the state of the user's keyboard
         */
        const Uint8* keyStates;

        /**
         * Default constructor
         */
        InputHandler();

        /**
         * Handles key up event
         */
        void handleKeyUp();

        /**
         * Handles key down event
         */
        void handleKeyDown();

        /**
         * Returns the current state of the keyboard
         *
         * @param numKeys The length of the returned array.
         *
         * @return
         */
        const Uint8* getKeyboardSnapshot(int *numKeys = nullptr) const;

    private:
        /**
         * Singleton instance
         */
        inline static InputHandler* instance = nullptr;
};

#endif  // INPUTS_INPUT_HANDLER_H
