#include <string>
#include <SDL2/SDL.h>

#include "Objects/GameObject.h"
#include "Objects/Properties.h"
#include "Physics/Transform.h"
#include "Physics/Point.h"

GameObject::GameObject(const Properties* properties)
    : textureID(properties->textureID),
      width(properties->width),
      height(properties->height),
      flip(properties->flip)
{
    this->transform = new Transform(properties->x, properties->y);

    // Set the initial position of this game object
    const float px = properties->x + (properties->width / 2);
    const float py = properties->y + (properties->height / 2);

    this->position = new Point(px, py);
}

Point* GameObject::getPosition() const
{
    return this->position;
}
