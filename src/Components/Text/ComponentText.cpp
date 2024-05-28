/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentText
*/

#include "ComponentText.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Text::Text(std::pair<float, float> pos, std::string text, int fontSize, Color color, std::string font)
                : _pos(pos), _text(text), _fontSize(fontSize), _color(color), _isDestroyed(false)
            {
                std::string path = "./assets/font/" + font;
                _font = LoadFont(path.c_str());
            }

            Text::~Text()
            {
                destroy();
            }

            void Text::destroy()
            {
                if (!_isDestroyed) {
                    UnloadFont(_font);
                    _isDestroyed = true;
                }
            }


            void Text::setPos(std::pair<float, float> pos)
            {
                _pos = pos;
            }

            void Text::setText(std::string text)
            {
                _text = text;
            }


            std::pair<float, float> Text::getSize() const
            {
                Vector2 size = MeasureTextEx(_font, _text.c_str(), _fontSize, 1);
                return std::make_pair(size.x, size.y);
            }


            void Text::draw()
            {
                if (_isDestroyed)
                    return;
                DrawTextEx(_font, _text.c_str(), Vector2{_pos.first, _pos.second}, _fontSize, 1, _color);
            }
        }
    }
}