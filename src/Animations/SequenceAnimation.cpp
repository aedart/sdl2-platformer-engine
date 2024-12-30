#include "Animations/SequenceAnimation.h"

#include <SDL2/SDL.h>
#include <tinyxml2.h>

#include "Animations/Animation.h"
#include "Animations/Sequence.h"
#include "Graphics/TextureManager.h"

SequenceAnimation::SequenceAnimation(const bool repeat):
    Animation(repeat)
{
}

void SequenceAnimation::update(const float delta)
{
    if (this->isRepeating() || !this->isDone()) {
        this->done = false;
        this->setCurrentFrame(
            (SDL_GetTicks() / this->sequence.speed) % this->sequence.frames
        );
    }

    const int lastFrame = this->sequence.frames - 1;
    if (!this->isRepeating() && this->getCurrentFrame() == lastFrame) {
        this->done = true;
        this->setCurrentFrame(lastFrame);
    }
}

void SequenceAnimation::draw(
    const float x,
    const float y,
    const float scaleX,
    const float scaleY,
    const SDL_RendererFlip flip
) const
{
    TextureManager::getInstance().drawFrame({
        .id = this->sequence.textureIDs[this->getCurrentFrame()],
        .x = static_cast<int>(x),
        .y = static_cast<int>(y),
        .width = static_cast<int>(this->sequence.width),
        .height = static_cast<int>(this->sequence.height),
        .scaleX = scaleX,
        .scaleY = scaleY,
        .row = 0,
        .column = 0,
        .flip = flip,
    });
}

bool SequenceAnimation::parse(const std::string& source)
{
    tinyxml2::XMLDocument document;

    // Attempt to load the source xml document.
    document.LoadFile(source.c_str());
    if (document.Error()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load animation file (ID %s): %s", source.c_str(), document.ErrorStr());
        return false;
    }

    // Obtain the root element (<map> element)
    const tinyxml2::XMLElement* root = document.RootElement();
    if (root == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Animation file is empty: %s", source.c_str());
        return false;
    }

    // Loop through each defined animation sequences and load them.
    for (const tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
        // Cast node's name to string for comparison...
        const std::string node = element->Name();

        if (node == "sequence") {
            const std::string id = element->Attribute("id");

            Sequence sequence {
                .speed = element->IntAttribute("speed"),
                .frames = element->IntAttribute("frames"),
                .width = element->IntAttribute("width"),
                .height = element->IntAttribute("height"),
            };

            for (const tinyxml2::XMLElement* frame = element->FirstChildElement(); frame != nullptr; frame = frame->NextSiblingElement()) {
                sequence.textureIDs.emplace_back(frame->Attribute("textureID"));
            }

            this->sequenceMap[id] = sequence;
        }
    }

    return true;
}

void SequenceAnimation::setCurrentSequence(const std::string& id)
{
    if (!this->sequenceMap.contains(id)) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Unable to find sequence for id: %s", id.c_str());
        return;
    }

    this->sequence = this->sequenceMap[id];
}
