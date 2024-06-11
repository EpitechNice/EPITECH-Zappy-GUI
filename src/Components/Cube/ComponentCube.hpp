/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentCube
*/

#ifndef COMPONENT_CUBE_HPP_
    #define COMPONENT_CUBE_HPP_

    #include <raylib.h>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Cube: public AComponent {
                public:
                    typedef enum {
                        CUBE,
                        WIRES,
                        CUBE_WIRES
                    } Mode;
                    Cube(Vector3 pos, Vector3 size, Color color, Mode mode);

                    void draw();

                protected:
                private:
                    Mode _mode;
            };
        }
    }
}

#endif /* !COMPONENT_CUBE_HPP_ */
