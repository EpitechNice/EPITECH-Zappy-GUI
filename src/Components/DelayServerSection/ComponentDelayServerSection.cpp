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
            DelayServerSection::DelayServerSection(std::pair<float, float> pos, std::pair<float, float> size, void (Zappy::GUI::Sfml::SoundManager::*method)(float))
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _callback = method;

                float partY = _sizeY / 4;
                _slider = std::make_unique<SliderVolume>(std::make_pair(_posX, _posY + partY * 2 - 10), _sizeX, 20);
            }

            void DelayServerSection::draw()
            {
                _slider->draw();
                (Zappy::GUI::Sfml::SoundManager::getInstance().*_callback)(_slider->getValue());
            }

            void DelayServerSection::update()
            {
                _slider->update();
            }
        }
    }
}