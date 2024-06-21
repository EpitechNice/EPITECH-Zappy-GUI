/*
** EPITECH PROJECT, 2024
** ù
** File description:
** ComponentVolumneSection
*/

#include "ComponentDelayServerSection.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            DelayServerSection::DelayServerSection(std::pair<float, float> pos, std::pair<float, float> size)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;

                float partY = _sizeY / 4;
                _slider = std::make_unique<SliderVolume>(std::make_pair(_posX, _posY + partY * 2 - 10), _sizeX, 20);

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
            }

            void DelayServerSection::draw()
            {
                _slider->draw();
            }

            void DelayServerSection::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;

                _slider->resize();
            }

            void DelayServerSection::update()
            {
                float tmp = _slider->getValue();
                _slider->update();
                if ((int)tmp != (int)_slider->getValue()) {
                    Zappy::GUI::Ressources::Ref::get()->ressources->frequency = (int)_slider->getValue() + 1;
                    Zappy::GUI::Ressources::Ref::get()->shared_memory->addCommand("sst " + std::to_string(Zappy::GUI::Ressources::Ref::get()->ressources->frequency));
                }
            }

            void DelayServerSection::setDelay(float delay)
            {
                _slider->setValue(delay - 1);
            }
        }
    }
}