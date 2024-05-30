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
                : _pos(pos), _size(size), _color(color)
            {
            }

            void Cubic::draw()
            {
                DrawCube(_pos, _size.x, _size.y, _size.z, _color);
            }

            void Cubic::setColor(Color color)
            {
                _color = color;
            }
        }
    }
}