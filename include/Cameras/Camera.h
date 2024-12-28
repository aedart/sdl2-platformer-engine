#ifndef CAMERAS_CAMERA_H
#define CAMERAS_CAMERA_H

#include <SDL2/SDL.h>
#include "Physics/Point.h"
#include "Physics/Vector2D.h"

/**
 * Camera
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Camera
{
    public:
        /**
         * Prevent copy constructor
         */
        Camera(const Camera&) = delete;

        /**
         * Prevent assignment
         *
         * @return
         */
        Camera& operator=(const Camera&) = delete;

        /**
         * Get singleton instance of this camera
         *
         * @return
         */
        static Camera& getInstance();

        /**
         * Destroy the camera instance
         */
        static void destroy();

        /**
         * Destructor
         */
        virtual ~Camera();

        /**
         * Get the camera's view box
         *
         * @return A rect that defines the visible area of the camera
         */
        [[nodiscard]] SDL_Rect getViewBox() const;

        /**
         * Get this camera's current position
         *
         * @return
         */
        [[nodiscard]] Vector2D getPosition() const;

        /**
         * Set this camera's targeted point
         *
         * @param point
         */
        void setTarget(Point* point);

        /**
         * Update this camera
         *
         * @param delta
         */
        void update(float delta);

    protected:
        /**
         * The target point of this camera
         */
        Point* target;

        /**
         * Current position of the camera
         */
        Vector2D position;

        /**
         * The camera's visible area
         */
        SDL_Rect viewBox;

        /**
         * Default constructor
         */
        Camera();

    private:
        /**
         * Singleton instance
         */
        inline static Camera* instance = nullptr;
};

#endif  // CAMERAS_CAMERA_H
