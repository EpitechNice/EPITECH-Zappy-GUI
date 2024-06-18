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

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
                _refStrokeSize = _strokeSize / _refWidth * 100;
            }


            void Rectangle::draw()
            {
                if (_strokeSize > 0)
                    DrawRectangle(_posX - _strokeSize, _posY - _strokeSize, _sizeX + _strokeSize * 2, _sizeY + _strokeSize * 2, _strokeColor);
                DrawRectangle(_posX, _posY, _sizeX, _sizeY, _color);
            }

            void Rectangle::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;
                _strokeSize = _refStrokeSize * _refWidth / 100;
                std::cout << "Stroke size: " << _strokeSize << std::endl;
            }


            void Rectangle::setStroke(float strokeSize, Color strokeColor)
            {
                _strokeSize = strokeSize;
                _refStrokeSize = _strokeSize / _refWidth * 100;
                _strokeColor = strokeColor;
            }
        }
    }
}