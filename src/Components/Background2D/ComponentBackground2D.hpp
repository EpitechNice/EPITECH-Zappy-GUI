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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Background2D {
                public:
                    Background2D(std::string texturePath, bool center = true);
                    ~Background2D();

                    void destroy();

                    void draw();

                protected:
                private:
                    int _posX;
                    int _posY;
                    Texture2D _texture;
                    bool _isDestroyed;
            };
        }
    }

}

#endif /* !COMPONENTBACKGROUND2D_HPP_ */
