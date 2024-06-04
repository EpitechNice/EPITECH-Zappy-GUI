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
                : _pos(pos), _radius(radius), _color(color)
            {
            }

            void Circle::draw()
            {
                DrawCircle(_pos.first, _pos.second, _radius, _color);
            }

            void Circle::modPosX(float x)
            {
                _pos.first += x;
            }

            void Circle::setPos(std::pair<float, float> pos)
            {
                _pos = pos;
            }

            void Circle::setRadius(float radius)
            {
                _radius = radius;
            }

            void Circle::setColor(Color color)
            {
                _color = color;
            }

            std::pair<float, float> Circle::getPos() const
            {
                return _pos;
            }

            float Circle::getRadius() const
            {
                return _radius;
            }

            Color Circle::getColor() const
            {
                return _color;
            }
        }
    }
}