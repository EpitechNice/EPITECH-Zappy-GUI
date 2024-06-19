/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentImage
*/

#ifndef COMPONENT_IMAGE_HPP_
    #define COMPONENT_IMAGE_HPP_

    #include <raylib.h>
    #include <string>

    #include "AComponent.hpp"
    #include "TextureManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Image component
             */
            class Image: public AComponent {
                public:
                    /**
                     * @brief Construct a new Image object
                     *
                     * @param path Path to the image
                     * @param pos Position of the image
                     * @param scale Scale of the image
                     *
                     * @warning The image will be loaded using the TextureManager. So it must be in the 'assets/images/' folder.
                     * @warning This function should be called in the raylib context
                     */
                    Image(std::string path, std::pair<float, float> pos, float scale);

                    /**
                     * @brief Draw the image
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the image
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                protected:
                private:
                    Texture2D _texture;
                    std::string _path;
            };
        }
    }
}

#endif /* !COMPONENTIMAGE_HPP_ */
