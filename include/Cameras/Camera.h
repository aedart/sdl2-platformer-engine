#ifndef CAMERAS_CAMERA_H
#define CAMERAS_CAMERA_H

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

    protected:
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
