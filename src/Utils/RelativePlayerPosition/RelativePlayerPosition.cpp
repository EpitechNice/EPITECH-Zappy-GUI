/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** RelativePlayerPosition
*/

#include "RelativePlayerPosition.hpp"

namespace Zappy {
    namespace GUI {
        RelativePlayerPosition *RelativePlayerPosition::get()
        {
            static RelativePlayerPosition instance;
            return &instance;
        }

        void RelativePlayerPosition::setStart(Vector3 start)
        {
            _start = start;
        }

        void RelativePlayerPosition::setTileSize(float tileSize)
        {
            _tileSize = tileSize;
        }

        Vector3 RelativePlayerPosition::getRelativePlayerPosition(int x, int y)
        {
            return Vector3{
                _start.x + (x * _tileSize),
                _tileSize + _tileSize / 2,
                _start.z + (y * _tileSize)
            };
        }
    }
}