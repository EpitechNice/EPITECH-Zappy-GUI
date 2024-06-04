/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentCubic
*/

#include "ComponentCubic.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Cubic::Cubic(Vector3 pos, Vector3 size, Color color)
                : _pos(pos), _size(size), _color(color), _mode(CUBE), _colorWires(BLACK)
            {
            }

            void Cubic::draw()
            {
                if (_mode == CUBE || _mode == CUBE_WIRES)
                    DrawCube(_pos, _size.x, _size.y, _size.z, _color);
                if (_mode == WIRES || _mode == CUBE_WIRES)
                    DrawCubeWires(_pos, _size.x, _size.y, _size.z, _colorWires);
            }

            void Cubic::setColor(Color color)
            {
                _color = color;
            }

            void Cubic::setPosY(float y)
            {
                _pos.y = y;
            }

            void Cubic::setMode(Mode mode)
            {
                _mode = mode;
            }

            void Cubic::setColorWires(Color color)
            {
                _colorWires = color;
            }
        }
    }
}