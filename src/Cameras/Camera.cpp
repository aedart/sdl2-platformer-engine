#include "Cameras/Camera.h"

Camera& Camera::getInstance()
{
    if (instance == nullptr) {
        instance = new Camera();
    }

    return *instance;
}
void Camera::destroy()
{
    delete instance;
}

Camera::~Camera()
{
    instance = nullptr;
}


// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Camera::Camera() = default;
