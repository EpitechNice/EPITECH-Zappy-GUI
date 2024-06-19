/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSliderVolume
*/

#include "ComponentSliderVolume.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            SliderVolume::SliderVolume(std::pair<float, float> pos, float width, float height)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = height;
                _active = true;
                _isDrag = false;

                _background = std::make_unique<Component::Rectangle>(std::make_pair(_posX, _posY), std::make_pair(_sizeX, _sizeY), GRAY);
                _value = std::make_unique<Component::Rectangle>(std::make_pair(_posX, _posY), std::make_pair(_sizeX, _sizeY), GREEN);
                setValue(50);

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
            }

            void SliderVolume::draw()
            {
                _background->draw();
                _value->draw();
            }

            void SliderVolume::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;

                _background->setPosX(_posX);
                _background->setPosY(_posY);
                _background->setSizeX(_sizeX);
                _background->setSizeY(_sizeY);

                _value->setPosX(_posX);
                _value->setPosY(_posY);
                _value->setSizeY(_sizeY);
                _value->setSizeX(_background->getSizeX() * value / 100);
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
        }
    }
}
