#ifndef GRAPHICS_TEXTURE_RENDER_PROPERTIES_H
#define GRAPHICS_TEXTURE_RENDER_PROPERTIES_H

#include <SDL2/SDL.h>

#include <string>

/**
 * Texture Render Properties
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class TextureRenderProperties
{
    public:
        /**
         * The id of the texture to be rendered
         */
        std::string id;

        /**
         * The target x position where texture must be rendered
         */
        int x;

        /**
         * The target y position where texture must be rendered
         */
        int y;

        /**
         * The width of the texture to be drawn in pixels
         */
        int width;

        /**
         * The height of the texture to be drawn in pixels
         */
        int height;

        /**
         * The row to be drawn, if rendering from a sprite sheet
         */
        int row = 0;

        /**
         * The column to be drawn, if rendering from a sprite sheet.
         *
         * This property is also known as the "frame" to be drawn.
         */
        int column = 0;

        /**
         * The angle that the texture must be rendered at
         */
        double angle = 0;

        /**
         * The flip mode (orientation of texture) when rendered
         */
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        /**
         * Scroll ratio of texture, if it must move in relation to camera.
         *
         * If 0 (zero), then texture will be fixed (camera does not follow).
         * If 1, then texture follows the camera.
         */
        float scrollRatio = 1.0;

        /**
         * Constructor
         *
         * @param id The id of the texture to be rendered
         * @param x X-axis offset
         * @param y Y-axis offset
         * @param width The width of the texture to be drawn in pixels
         * @param height The height of the texture to be drawn in pixels
         */
        TextureRenderProperties(
            std::string id,
            int x,
            int y,
            int width,
            int height
        );

        /**
         * Constructor
         *
         * @param id The id of the texture to be rendered
         * @param x X-axis offset
         * @param y Y-axis offset
         * @param width The width of the texture to be drawn in pixels
         * @param height The height of the texture to be drawn in pixels
         * @param row The row to be drawn, if rendering from a sprite sheet
         * @param column The column (frame) to be drawn, if rendering from a sprite sheet
         * @param angle The angle that the texture must be rendered at
         * @param flip The flip mode (orientation of texture) when rendered
         * @param scrollRatio Scroll ratio of texture, if it must move in relation to camera
         */
        TextureRenderProperties(
            std::string id,
            int x,
            int y,
            int width,
            int height,
            int row = 0,
            int column = 0,
            double angle = 0,
            SDL_RendererFlip flip = SDL_FLIP_NONE,
            float scrollRatio = 1.0
        );

        /**
         * Get the source rect
         *
         * @return
         */
        [[nodiscard]] SDL_Rect getSource() const;

        /**
         * Get the destination rect
         *
         * @return
         */
        [[nodiscard]] SDL_Rect getDestination() const;
};

#endif  // GRAPHICS_TEXTURE_RENDER_PROPERTIES_H
