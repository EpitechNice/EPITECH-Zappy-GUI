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
            class Circle: public AComponent {
                public:
                    Circle(std::pair<float, float> pos, float radius, Color color);

                    void draw();

                    void setRadius(float radius);
                    float getRadius() const;

                protected:
                private:
                    float _radius;
            };
        }
    }
}

#endif /* !COMPONENT_CIRCLE_HPP_ */
