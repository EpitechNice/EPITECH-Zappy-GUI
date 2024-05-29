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
                _height += _texts.back()->getSize().second + _gap;
            }

            void TextGroup::setPosX(int x)
            {
                _pos.first = x;
                for (auto &text : _texts)
                    text->setPosX(x);
            }
        }
    }
}