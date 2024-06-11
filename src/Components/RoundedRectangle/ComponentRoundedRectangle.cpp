/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentRoundedRectangle
*/

#include "ComponentRoundedRectangle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            RoundedRectangle::RoundedRectangle(std::pair<float, float> pos, std::pair<float, float> size, float radius, Color color)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _radius = radius;
                _color = color;
            }


            void RoundedRectangle::draw()
            {
                DrawRectangleRounded({ _posX, _posY, _sizeX, _sizeY }, _radius, 0, _color);
            }


            void RoundedRectangle::setRadius(float radius)
            {
                _radius = radius;
            }

            float RoundedRectangle::getRadius() const
            {
                return _radius;
            }
        }
    }
}