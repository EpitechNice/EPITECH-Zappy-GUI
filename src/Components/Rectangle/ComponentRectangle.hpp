/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentRectangle
*/

#ifndef COMPONENT_RECTANGLE_HPP_
    #define COMPONENT_RECTANGLE_HPP_

    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief A rectangle component
             */
            class Rectangle : public AComponent {
                public:
                    /**
                     * @brief Construct a new Rectangle object
                     *
                     * @param pos The position of the rectangle
                     * @param size The size of the rectangle
                     * @param color The color of the rectangle
                    */
                    Rectangle(std::pair<int, int> pos, std::pair<int, int> size, Color color);

                    /**
                     * @brief Draw the rectangle
                     *
                     * @warning This function have to be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the rectangle
                     */
                    void resize() override;

                    /**
                     * @brief Set the Stroke object
                     *
                     * @param strokeSize The size of the stroke
                     * @param strokeColor The color of the stroke
                     */
                    void setStroke(float strokeSize, Color strokeColor);

                protected:
                private:
                    float _strokeSize = -1;
                    Color _strokeColor;

                    float _refStrokeSize;
            };
        }
    }
}

#endif /* !COMPONENT_RECTANGLE_HPP_ */
