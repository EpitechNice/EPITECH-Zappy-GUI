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
            /**
             * @brief Cube component
             */
            class Cube: public AComponent {
                public:
                    /**
                     * @brief Cube mode
                     *
                     * @note `CUBE` Draw a cube
                     * @note `WIRES` Draw the wires of a cube
                     * @note `CUBE_WIRES` Draw a cube and its wires
                     */
                    typedef enum {
                        CUBE,
                        WIRES,
                        CUBE_WIRES
                    } Mode;

                    /**
                     * @brief Construct a new Cube object
                     *
                     * @param pos The position of the cube
                     * @param size The size of the cube
                     * @param color The color of the cube
                     * @param mode The mode of the cube
                     */
                    Cube(Vector3 pos, Vector3 size, Color color, Mode mode);

                    /**
                     * @brief Draw the cube
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                protected:
                private:
                    Mode _mode;
            };
        }
    }
}

#endif /* !COMPONENT_CUBE_HPP_ */
