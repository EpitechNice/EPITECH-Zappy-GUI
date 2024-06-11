/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentRectangle
*/

#include "ComponentRectangle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Rectangle::Rectangle(std::pair<int, int> pos, std::pair<int, int> size, Color color)
            {
                _posX = pos.first;
                _posY = pos.second;
                _color = color;
                _sizeX = size.first;
                _sizeY = size.second;
                _color = color;

                _strokeColor = BLACK;
                _strokeSize = -1;
            }


            void Rectangle::draw()
            {
                if (_strokeSize >= 1)
                    DrawRectangle(_posX - _strokeSize, _posY - _strokeSize, _sizeX + _strokeSize * 2, _sizeY + _strokeSize * 2, _strokeColor);
                DrawRectangle(_posX, _posY, _sizeX, _sizeY, _color);
            }


            void Rectangle::setStroke(int strokeSize, Color strokeColor)
            {
                _strokeSize = strokeSize;
                _strokeColor = strokeColor;
            }
        }
    }
}