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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class RoundedRectangle {
                public:
                    RoundedRectangle(std::pair<float, float> pos, std::pair<float, float> size, float radius, Color color);
                    ~RoundedRectangle() = default;

                    void setPosition(std::pair<float, float> pos);
                    void setSize(std::pair<float, float> size);
                    void setRadius(float radius);
                    void setColor(Color color);

                    std::pair<float, float> getPosition() const;
                    std::pair<float, float> getSize() const;
                    float getRadius() const;
                    Color getColor() const;

                    void draw();

                protected:
                private:
                    std::pair<float, float> _pos;
                    std::pair<float, float> _size;
                    float _radius;
                    Color _color;
                    Rectangle _rec;
            };
        }
    }
}

#endif /* !COMPONENT_ROUNDED_RECTANGLE_HPP_ */
