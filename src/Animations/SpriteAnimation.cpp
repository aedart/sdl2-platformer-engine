#include "Animations/SpriteAnimation.h"

#include "Animations/Animation.h"
#include "Graphics/TextureManager.h"

SpriteAnimation::SpriteAnimation(const bool repeat):
    Animation(repeat)
{
    this->frames = 1;
    this->row = 0;
    this->column = 0;
    this->speed = 50;
}

void SpriteAnimation::update(const float delta)
{
    if (this->isRepeating() || !this->isDone()) {
        this->done = false;
        this->setCurrentFrame(
            (SDL_GetTicks() / this->speed) % this->frames
        );
    }

    const int lastFrame = this->frames - 1;
    if (!this->isRepeating() && this->getCurrentFrame() == lastFrame) {
        this->done = true;
        this->setCurrentFrame(lastFrame);
    }
}

void SpriteAnimation::draw(
    const float x,
    const float y,
    const float width,
    const float height,
    const float scaleX,
    const float scaleY,
    const SDL_RendererFlip flip
) const
{
    TextureManager::getInstance().drawFrame({
        .id = this->textureID,
        .x = static_cast<int>(x),
        .y = static_cast<int>(y),
        .width = static_cast<int>(width),
        .height = static_cast<int>(height),
        .scaleX = scaleX,
        .scaleY = scaleY,
        .row = this->row,
        .column = this->column + this->currentFrame,
        .flip = flip,
    });
}

void SpriteAnimation::setProperties(
    const std::string& textureID,
    const int frames,
    const int speed,
    const int row,
    const int column
)
{
    this->textureID = textureID;
    this->frames = frames;
    this->speed = speed;
    this->row = row;
    this->column = column;
}

void SpriteAnimation::setRow(const int row)
{
    this->row = row;
}

int SpriteAnimation::getRow() const
{
    return this->row;
}

void SpriteAnimation::setColumn(const int column)
{
    this->column = column;
}

int SpriteAnimation::getColumn() const
{
    return this->column;
}

void SpriteAnimation::incrementRow()
{
    this->row++;
}

void SpriteAnimation::decrementRow()
{
    if (this->row - 1 > -1) {
        this->row--;
    }
}

void SpriteAnimation::incrementColumn()
{
    this->column++;
}

void SpriteAnimation::decrementColumn()
{
    if (this->column - 1 > -1) {
        this->column--;
    }
}
