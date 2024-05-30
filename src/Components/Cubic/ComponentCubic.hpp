/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentCubic
*/

#ifndef COMPONENT_CUBIC_HPP_
#define COMPONENT_CUBIC_HPP_

    #include <raylib.h>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Cubic {
                public:
                    Cubic(Vector3 pos, Vector3 size, Color color);
                    ~Cubic() = default;

                    void draw();

                    void setColor(Color color);

                protected:
                private:
                    Vector3 _pos;
                    Vector3 _size;
                    Color _color;
            };
        }
    }
}

#endif /* !COMPONENT_CUBIC_HPP_ */
