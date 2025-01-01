#include "Physics/Collider.h"

#include "SDL2/SDL.h"

#include "Core/Engine.h"
#include "Cameras/Camera.h"
#include "Collisions/CollisionHandler.h"
#include "Physics/Vector2D.h"

Collider::Collider(const SDL_Rect box, const SDL_Rect buffer)
{
    this->setBuffer(buffer.x, buffer.y, buffer.w, buffer.h);
    this->setBox(box.x, box.y, box.w, box.h);
}

void Collider::setBox(const int x, const int y, const int w, const int h)
{
    this->box = SDL_Rect{
        x - this->buffer.x,
        y - this->buffer.y,
        w - this->buffer.w,
        h - this->buffer.h
    };
}

SDL_Rect Collider::getBox() const
{
    return this->box;
}

void Collider::setBuffer(const int x, const int y, const int w, const int h)
{
    this->buffer = SDL_Rect{ x, y, w, h };
}

SDL_Rect Collider::getBuffer() const
{
    return this->buffer;
}

bool Collider::collidesWithMap() const
{
    return CollisionHandler::getInstance().mapCollision(this->getBox());
}

void Collider::draw()
{
    const Vector2D camaraPosition = Camera::getInstance().getPosition();

    const SDL_Rect box = {
        .x = static_cast<int>(this->box.x + camaraPosition.x),
        .y = static_cast<int>(this->box.y + camaraPosition.y),
        .w = this->box.w,
        .h = this->box.h
    };

    SDL_RenderDrawRect(Engine::getInstance().getRenderer(), &box);
}
