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
                : _pos(pos), _size(size), _radius(radius), _color(color)
            {
                _rec = {pos.first, pos.second, size.first, size.second};
            }


            void RoundedRectangle::setPosition(std::pair<float, float> pos)
            {
                _pos = pos;
                _rec = {pos.first, pos.second, _size.first, _size.second};
            }

            void RoundedRectangle::setSize(std::pair<float, float> size)
            {
                _size = size;
                _rec = {_pos.first, _pos.second, size.first, size.second};
            }

            void RoundedRectangle::setRadius(float radius)
            {
                _radius = radius;
            }

            void RoundedRectangle::setColor(Color color)
            {
                _color = color;
            }



            std::pair<float, float> RoundedRectangle::getPosition() const
            {
                return _pos;
            }

            std::pair<float, float> RoundedRectangle::getSize() const
            {
                return _size;
            }

            float RoundedRectangle::getRadius() const
            {
                return _radius;
            }

            Color RoundedRectangle::getColor() const
            {
                return _color;
            }

            void RoundedRectangle::draw()
            {
                DrawRectangleRounded(_rec, _radius, 0, _color);
            }
        }
    }
}