/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentBackground2D
*/

#ifndef COMPONENT_BACKGROUND_2D_HPP_
    #define COMPONENT_BACKGROUND_2D_HPP_

    #include <raylib.h>
    #include <string>

    #include "AComponent.hpp"
    #include "TextureManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Background2D component
             *
             * @details This component is used to display a 2D background that covers the whole window
             */
            class Background2D: public AComponent {
                public:
                    /**
                     * @brief Construct a new Background2D object
                     *
                     * @param texturePath Path to the texture to use as background.
                     *
                     * @note The texture will be loaded using the TextureManager. So it must be in the 'assets/img/' folder.
                     */
                    Background2D(std::string texturePath);

                    /**
                     * @brief Draw the background
                     */
                    void draw() override;

                    /**
                     * @brief Resize the background to fit the window
                     */
                    void resize() override;

                protected:
                private:
                    Texture2D _texture;
                    std::string _texturePath;
            };
        }
    }

}

#endif /* !COMPONENT_BACKGROUND_2D_HPP_ */
