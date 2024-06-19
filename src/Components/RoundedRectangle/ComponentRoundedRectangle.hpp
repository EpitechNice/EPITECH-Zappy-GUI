/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentRoundedRectangle
*/

#ifndef COMPONENT_ROUNDED_RECTANGLE_HPP_
    #define COMPONENT_ROUNDED_RECTANGLE_HPP_

    #include <raylib.h>
    #include <raymath.h>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief A rounded rectangle component
             */
            class RoundedRectangle: public AComponent {
                public:
                    /**
                     * @brief Construct a new RoundedRectangle object
                     *
                     * @param pos The position of the rectangle
                     * @param size The size of the rectangle
                     * @param radius The radius of the rectangle
                     * @param color The color of the rectangle
                     */
                    RoundedRectangle(std::pair<float, float> pos, std::pair<float, float> size, float radius, Color color);

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
                     * @brief Set the radius of the rectangle
                     *
                     * @param radius The radius of the rectangle
                     */
                    void setRadius(float radius);

                    /**
                     * @brief Get the radius of the rectangle
                     *
                     * @return `float` The radius of the rectangle
                     */
                    float getRadius() const;

                protected:
                private:
                    float _radius;
                    float _refRadius;
            };
        }
    }
}

#endif /* !COMPONENT_ROUNDED_RECTANGLE_HPP_ */
