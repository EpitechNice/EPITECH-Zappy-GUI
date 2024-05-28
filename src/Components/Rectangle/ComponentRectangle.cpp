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
                : _pos(pos), _size(size), _color(color)
            {
                _strokeColor = BLACK;
                _strokeSize = -1;
            }


            void Rectangle::draw()
            {
                if (_strokeSize >= 1)
                    DrawRectangle(_pos.first - _strokeSize, _pos.second - _strokeSize, _size.first + _strokeSize * 2, _size.second + _strokeSize * 2, _strokeColor);
                DrawRectangle(_pos.first, _pos.second, _size.first, _size.second, _color);
            }


            void Rectangle::setStroke(int strokeSize, Color strokeColor)
            {
                _strokeSize = strokeSize;
                _strokeColor = strokeColor;
            }

            void Rectangle::unsetStroke()
            {
                _strokeSize = -1;
            }

            void Rectangle::setPosX(int x)
            {
                _pos.first = x;
            }
        }
    }
}