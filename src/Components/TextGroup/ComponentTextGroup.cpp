/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextGroup
*/

#include "ComponentTextGroup.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            TextGroup::TextGroup(std::pair<int, int> pos, int width, int gap)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = 0;
                _gap = gap;
                _texts.clear();

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
            }

            void TextGroup::draw()
            {
                for (auto &text : _texts)
                    text->draw();
            }

            void TextGroup::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;

                int tmp = 0;
                for (auto &text : _texts) {
                    text->resize();
                    text->setPosX(_posX);
                    text->setPosY(_posY + tmp);
                    tmp += text->getSizeY() + _gap;
                }
            }

            void TextGroup::addText(std::string name, std::string text, int gap, Color color)
            {
                _texts.push_back(std::make_unique<TextMessage>(std::make_pair(_posX, _posY + _sizeY), _sizeX, name, text, gap, color));
                _sizeY += _texts.back()->getSizeY() + _gap;
            }

            void TextGroup::setPosX(float x)
            {
                _posX = x;
                for (auto &text : _texts)
                    text->setPosX(x);
                _refPosX = _posX / _refWidth * 100;
            }

            void TextGroup::setPosY(float y)
            {
                _posY = y;
                int tmp = 0;
                for (auto &text : _texts) {
                    text->setPosY(y + tmp);
                    tmp += text->getSizeY() + _gap;
                }
                _refPosY = _posY / _refHeight * 100;
            }
        }
    }
}