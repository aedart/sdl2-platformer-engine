#include "Physics/Collider.h"

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
