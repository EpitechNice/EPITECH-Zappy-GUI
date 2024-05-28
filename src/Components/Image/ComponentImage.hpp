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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Image {
                public:
                    Image(std::string path, std::pair<float, float> pos, float scale);
                    ~Image();

                    void destroy();

                    void draw();

                    void setPos(std::pair<float, float> pos);

                    std::pair<int, int> getSize();

                protected:
                private:
                    bool _isDestroyed;
                    std::string _path;
                    std::pair<float, float> _pos;
                    Texture2D _texture;
            };
        }
    }
}

#endif /* !COMPONENTIMAGE_HPP_ */
