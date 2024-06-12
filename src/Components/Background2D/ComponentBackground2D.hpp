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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Background2D: AComponent {
                public:
                    Background2D(std::string texturePath, bool center = true);

                    void destroy() override;
                    void draw() override;

                protected:
                private:
                    Texture2D _texture;
            };
        }
    }

}

#endif /* !COMPONENTBACKGROUND2D_HPP_ */
