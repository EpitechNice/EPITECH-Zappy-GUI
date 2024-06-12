/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentCircle
*/

#include "ComponentCircle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Circle::Circle(std::pair<float, float> pos, float radius, Color color)
            {
                _posX = pos.first;
                _posY = pos.second;
                _radius = radius;
                _color = color;
            }

            void Circle::draw()
            {
                DrawCircle(_posX, _posY, _radius, _color);
            }

            void Circle::setRadius(float radius)
            {
                _radius = radius;
            }

            float Circle::getRadius() const
            {
                return _radius;
            }
        }
    }
}
