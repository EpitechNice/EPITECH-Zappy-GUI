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
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = height;
                _active = true;
                _name = name;
                _isDrag = false;

                _background = std::make_unique<Component::Rectangle>(std::make_pair(_posX, _posY), std::make_pair(_sizeX, _sizeY), GRAY);
                _value = std::make_unique<Component::Rectangle>(std::make_pair(_posX, _posY), std::make_pair(_sizeX, _sizeY), GREEN);
                setValue(50);
            }

            void SliderVolume::draw()
            {
                _background->draw();
                _value->draw();
            }

            void SliderVolume::update()
            {
                if (!_active) return;
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(GetMousePosition(), { _posX, _posY, _sizeX, _sizeY }))
                        _isDrag = true;
                } else
                    _isDrag = false;
                if (_isDrag) {
                    _value->setSizeX(GetMousePosition().x - _posX);
                    if (_value->getSizeX() < 0) _value->setSizeX(0);
                    if (_value->getSizeX() > _sizeX) _value->setSizeX(_sizeX);
                }
            }


            void SliderVolume::setActive(bool active)
            {
                if (_active == active) return;
                _active = active;
                if (_active) {
                    _background->setColor(GRAY);
                    _value->setColor(GREEN);
                } else {
                    _background->setColor(Fade(GRAY, 0.3f));
                    _value->setColor(Fade(GREEN, 0.3f));
                }
            }

            void SliderVolume::setValue(float value)
            {
                _value->setSizeX(_background->getSizeX() * value / 100);
            }

            bool SliderVolume::getActive() const
            {
                return _active;
            }

            float SliderVolume::getValue() const
            {
                if (!_active) return 0;
                return _value->getSizeX() / _background->getSizeX() * 100;
            }

            std::string SliderVolume::getName() const
            {
                return _name;
            }
        }
    }
}
