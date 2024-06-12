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
                : _pos(pos), _width(width), _height(0), _gap(gap), _isDestroyed(false)
            {
                _texts.clear();
            }

            TextGroup::~TextGroup()
            {
                if (!_isDestroyed)
                    destroy();
            }

            void TextGroup::destroy()
            {
                _texts.clear();
                _isDestroyed = true;
            }

            void TextGroup::draw()
            {
                for (auto &text : _texts)
                    text->draw();
            }

            void TextGroup::addText(std::string name, std::string text, int gap, Color color)
            {
                _texts.push_back(std::make_unique<TextMessage>(std::make_pair(_pos.first, _pos.second + _height), _width, name, text, gap, color));
                _height += _texts.back()->getSizeY() + _gap;
            }

            void TextGroup::setPosX(int x)
            {
                _pos.first = x;
                for (auto &text : _texts)
                    text->setPosX(x);
            }

            void TextGroup::setPosY(int y)
            {
                _pos.second = y;
                int tmp = 0;
                for (auto &text : _texts) {
                    text->setPosY(y + tmp);
                    tmp += text->getSizeY() + _gap;
                }
            }

            std::pair<int, int> TextGroup::getPos()
            {
                return _pos;
            }

            std::pair<int, int> TextGroup::getSize()
            {
                return std::make_pair(_width, _height);
            }
        }
    }
}