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

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
                _refRadius = _radius / _refWidth * 100;
            }


            void RoundedRectangle::draw()
            {
                DrawRectangleRounded({ _posX, _posY, _sizeX, _sizeY }, _radius, 0, _color);
            }

            void RoundedRectangle::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;
                _radius = _refRadius * _refWidth / 100;
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