/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSliderVolume
*/

#include "SliderVolume.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            SliderVolume::SliderVolume(std::pair<float, float> pos, float width, float height, std::string name)
                : _pos(pos), _width(width), _height(height), _value(0.5f), _isDragging(false), _isDestroyed(false), _name(name)
            {
            }

            SliderVolume::~SliderVolume()
            {
                destroy();
            }

            void SliderVolume::destroy()
            {
                if (!_isDestroyed) {
                    _isDestroyed = true;
                }
            }

            void SliderVolume::draw()
            {
                DrawRectangle(_pos.first, _pos.second, _width, _height, GRAY);
                float cursorX = _pos.first + _value * (_width - 20);
                DrawRectangle(cursorX, _pos.second, 20, _height, GREEN);
                DrawRectangle(_pos.first, _pos.second, cursorX - _pos.first, _height, GREEN);
            }

            bool SliderVolume::isClicked()
            {
                Rectangle cursorRect = { _pos.first, _pos.second, _width, _height };
                if (CheckCollisionPointRec(GetMousePosition(), cursorRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    float mouseX = GetMouseX();
                    float newValue = (mouseX - _pos.first) / _width;
                    if (newValue < 0)
                        newValue = 0;
                    else if (newValue > 1)
                        newValue = 1;
                    _value = newValue;
                    return true;
                }
                return false;
            }

            void SliderVolume::updateValue()
            {
                float mouseX = GetMouseX();
                float newValue = (mouseX - _pos.first) / _width;
                if (newValue < 0)
                    newValue = 0;
                else if (newValue > 1)
                    newValue = 1;
                _value = newValue;
            }

            void SliderVolume::event()
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    _isDragging = true;
                    if (isClicked()) {
                        updateValue();
                    }
                } else {
                    _isDragging = false;
                }
            }
        }
    }
}
