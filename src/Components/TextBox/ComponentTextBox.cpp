/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextBox
*/

#include "ComponentTextBox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            TextBox::TextBox(std::pair<int, int> pos, int size, std::string text, int fontSize, Color color, std::string font)
                : _pos(pos), _size(size), _text(text), _fontSize(fontSize), _color(color), _isDestroyed(false)
            {
                std::string path = "./assets/font/" + font;
                _font = LoadFont(path.c_str());
                setText(text);
            }

            TextBox::~TextBox()
            {
                destroy();
            }

            void TextBox::destroy()
            {
                if (!_isDestroyed) {
                    UnloadFont(_font);
                    _isDestroyed = true;
                }
            }

            void TextBox::setPosX(int x)
            {
                _pos.first = x;
            }

            void TextBox::setPosY(int y)
            {
                _pos.second = y;
            }

            void TextBox::setPos(std::pair<int, int> pos)
            {
                _pos = pos;
            }

            void TextBox::setText(std::string text)
            {
                std::string tmp = "";
                _text = "";

                for (auto c : text) {
                    tmp = _text + c;
                    if (MeasureTextEx(_font, tmp.c_str(), _fontSize, 1).x > _size)
                        _text += '\n';
                    _text += c;
                }
            }

            std::pair<float, float> TextBox::getSize() const
            {
                Vector2 size = MeasureTextEx(_font, _text.c_str(), _fontSize, 1);
                return std::make_pair(size.x, size.y);
            }

            void TextBox::draw()
            {
                if (_isDestroyed)
                    return;
                DrawTextEx(_font, _text.c_str(), Vector2{(float)_pos.first, (float)_pos.second}, _fontSize, 1, _color);
            }
        }
    }
}