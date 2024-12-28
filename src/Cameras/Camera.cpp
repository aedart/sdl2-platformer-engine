#include "Core/Engine.h"

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
    delete this->target;

    instance = nullptr;
}

SDL_Rect Camera::getViewBox() const
{
    return this->viewBox;
}

Vector2D Camera::getPosition() const
{
    return this->position;
}

void Camera::setTarget(Point* point)
{
    this->target = point;
}

void Camera::update(float delta)
{
    if (this->target == nullptr) {
        return;
    }

    // TODO: Handling of delta?...
    // TODO: ...also, these are some pretty hard-coded width / height values !?

    const auto& engine = Engine::getInstance();
    const auto screenWidth = engine.getScreenWidth();
    const auto screenHeight = engine.getScreenHeight();

    this->viewBox.x = this->target->x - screenWidth / 2;
    this->viewBox.y = this->target->y - screenHeight / 2;

    if (this->viewBox.x < 0) {
        this->viewBox.x = 0;
    }

    if (this->viewBox.y < 0) {
        this->viewBox.y = 0;
    }

    const auto maxWidth = (2 * screenWidth - this->viewBox.w);
    if (this->viewBox.x > maxWidth) {
        this->viewBox.x = maxWidth;
    }

    const auto maxHeight = (screenHeight - this->viewBox.h);
    if (this->viewBox.y > maxHeight) {
        this->viewBox.y = maxHeight;
    }

    this->position = Vector2D(this->viewBox.x, this->viewBox.y);
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Camera::Camera():
    target(nullptr),
    position(),

    // Initialise the view box according to the engine's screen width and height.
    viewBox(0, 0, Engine::getInstance().getScreenWidth(), Engine::getInstance().getScreenHeight())
{
}
