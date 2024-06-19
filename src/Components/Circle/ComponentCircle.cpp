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

                setRef();
                _refRadius = _radius / _refWidth * 100;
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
            }

            void Circle::draw()
            {
                DrawCircle(_posX, _posY, _radius, _color);
            }

            void Circle::resize()
            {
                setRef();
                _radius = _refRadius * _refWidth / 100;
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
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
