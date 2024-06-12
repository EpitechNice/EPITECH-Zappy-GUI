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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Image: public AComponent {
                public:
                    Image(std::string path, std::pair<float, float> pos, float scale);

                    void destroy() override;
                    void draw() override;

                protected:
                private:
                    std::string _path;
                    Texture2D _texture;
            };
        }
    }
}

#endif /* !COMPONENTIMAGE_HPP_ */
