#include "Animations/Animation.h"

Animation::Animation(const bool repeat):
    repeat(repeat),
    done(false),
    currentFrame(0)
{
}

void Animation::setRepeat(const bool repeat)
{
    this->repeat = repeat;
}

bool Animation::isRepeating() const
{
    return this->repeat;
}

bool Animation::isDone() const
{
    return this->done;
}

void Animation::setCurrentFrame(const int frame)
{
    this->currentFrame = frame;
}

int Animation::getCurrentFrame() const
{
    return this->currentFrame;
}
