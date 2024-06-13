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
            class RoundedRectangle: public AComponent {
                public:
                    RoundedRectangle(std::pair<float, float> pos, std::pair<float, float> size, float radius, Color color);

                    void draw() override;

                    void setRadius(float radius);
                    float getRadius() const;

                protected:
                private:
                    float _radius;
            };
        }
    }
}

#endif /* !COMPONENT_ROUNDED_RECTANGLE_HPP_ */
