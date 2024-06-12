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
            }

            void TextGroup::draw()
            {
                for (auto &text : _texts)
                    text->draw();
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
            }

            void TextGroup::setPosY(float y)
            {
                _posY = y;
                int tmp = 0;
                for (auto &text : _texts) {
                    text->setPosY(y + tmp);
                    tmp += text->getSizeY() + _gap;
                }
            }
        }
    }
}