/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentCube
*/

#include "ComponentCube.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Cube::Cube(Vector3 pos, Vector3 size, Color color, Mode mode)
            {
                _posX = pos.x;
                _posY = pos.y;
                _posZ = pos.z;
                _sizeX = size.x;
                _sizeY = size.y;
                _sizeZ = size.z;
                _color = color;
                _mode = mode;
            }

            void Cube::draw()
            {
                if (_mode == CUBE || _mode == CUBE_WIRES)
                    DrawCube({ _posX, _posY, _posZ }, _sizeX, _sizeY, _sizeZ, _color);
                if (_mode == WIRES || _mode == CUBE_WIRES)
                    DrawCubeWires({ _posX, _posY, _posZ }, _sizeX, _sizeY, _sizeZ, _color);
            }
        }
    }
}