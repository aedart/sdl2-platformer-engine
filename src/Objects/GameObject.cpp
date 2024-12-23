#include <string>
#include <SDL2/SDL.h>

#include "Objects/GameObject.h"
#include "Objects/Properties.h"
#include "Physics/Transform.h"

GameObject::GameObject(const Properties* properties):
    textureID(properties->textureID),
    width(properties->width),
    height(properties->height),
    flip(properties->flip)
{
    this->transform = new Transform(properties->x, properties->y);
}
