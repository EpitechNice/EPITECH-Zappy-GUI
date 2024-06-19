/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentCircle
*/

#ifndef COMPONENT_CIRCLE_HPP_
    #define COMPONENT_CIRCLE_HPP_

    #include <raylib.h>
    #include <raymath.h>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Circle component
             */
            class Circle: public AComponent {
                public:
                    /**
                     * @brief Construct a new Circle object
                     *
                     * @param pos The position of the circle
                     * @param radius The radius of the circle
                     * @param color The color of the circle
                     */
                    Circle(std::pair<float, float> pos, float radius, Color color);

                    /**
                     * @brief Draw the circle
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the circle
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the radius of the circle
                     *
                     * @param radius The new radius of the circle
                     */
                    void setRadius(float radius);

                    /**
                     * @brief Get the radius of the circle
                     *
                     * @return `float` The radius of the circle
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

#endif /* !COMPONENT_CIRCLE_HPP_ */
