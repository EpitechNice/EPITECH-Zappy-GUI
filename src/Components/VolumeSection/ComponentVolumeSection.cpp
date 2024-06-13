/*
** EPITECH PROJECT, 2024
** ù
** File description:
** ComponentVolumneSection
*/

#include "ComponentVolumeSection.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            VolumeSection::VolumeSection(std::pair<float, float> pos, std::pair<float, float> size, std::string text, void (Zappy::GUI::Sfml::SoundManager::*method)(float))
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _callback = method;

                float partY = _sizeY / 4;

                _text = std::make_unique<Component::Text>(std::make_pair(0, 0), text, 40, WHITE);
                _text->setPosX(_posX + _sizeX / 2 - _text->getSizeX() / 2);
                _text->setPosY(_posY + partY - _text->getSizeY() / 2);

                _slider = std::make_unique<SliderVolume>(std::make_pair(_posX, _posY + partY * 2 - 10), _sizeX, 20);

                _on = std::make_unique<Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), "ON", 25, GREEN);
                _on->setPosX(_posX + (_sizeX / 3) - _on->getSizeX() / 2);
                _on->setPosY(_posY + partY * 3 - _on->getSizeY() / 2);

                _off = std::make_unique<Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), "OFF", 25, RED);
                _off->setPosX(_posX + (_sizeX / 3) * 2 - _off->getSizeX() / 2);
                _off->setPosY(_posY + partY * 3 - _off->getSizeY() / 2);
            }

            void VolumeSection::draw()
            {
                _slider->draw();
                _text->draw();
                _on->draw();
                _off->draw();

                if (_slider->getActive()) {
                    if (_off->isClicked()) {
                        _slider->setActive(false);
                        (Zappy::GUI::Sfml::SoundManager::getInstance().*_callback)(0);
                        Sfml::SoundManager::getInstance().setEffetSonore("assets/Musique/effetSonoreButton1.wav");
                        Sfml::SoundManager::getInstance().playButtonClickSound();
                    } else {
                        (Zappy::GUI::Sfml::SoundManager::getInstance().*_callback)(_slider->getValue());
                    }
                } else {
                    if (_on->isClicked()) {
                        _slider->setActive(true);
                        (Zappy::GUI::Sfml::SoundManager::getInstance().*_callback)(_slider->getValue());
                        Sfml::SoundManager::getInstance().setEffetSonore("assets/Musique/effetSonoreButton1.wav");
                        Sfml::SoundManager::getInstance().playButtonClickSound();
                    }
                }
            }

            void VolumeSection::update()
            {
                _slider->update();
            }

            void VolumeSection::setText(std::string text)
            {
                _text->setText(text);
                _text->setPosX(_posX + _sizeX / 2 - _text->getSizeX() / 2);
            }
        }
    }
}