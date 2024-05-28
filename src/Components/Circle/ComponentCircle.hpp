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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Circle {
                public:
                    Circle(std::pair<float, float> pos, float radius, Color color);
                    ~Circle() = default;

                    void draw();

                    void setPos(std::pair<float, float> pos);
                    void setRadius(float radius);
                    void setColor(Color color);

                    std::pair<float, float> getPos() const;
                    float getRadius() const;
                    Color getColor() const;

                protected:
                private:
                    std::pair<float, float> _pos;
                    float _radius;
                    Color _color;
            };
        }
    }
}

#endif /* !COMPONENT_CIRCLE_HPP_ */
