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
            TextBox::TextBox(std::pair<int, int> pos, int width, std::string text, int fontSize, Color color, std::string font)
            {
                _posX = pos.first;
                _posY = pos.second;
                _width = width;
                _text = text;
                _fontSize = fontSize;
                _color = color;

                _font = Zappy::GUI::Raylib::FontManager::get()->getFont(font);
                setText(text);
            }

            void TextBox::setText(std::string text)
            {
                std::string tmp = "";
                _text = "";

                for (std::size_t i = 0; i < text.size(); i++) {
                    tmp = _text + text[i];
                    if (text[i] == '\\' && text[i + 1] == 'n' && i + 1 < text.size()) {
                        _text += '\n';
                        i++;
                        continue;
                    }
                    if (MeasureTextEx(_font, tmp.c_str(), _fontSize, 1).x > _width)
                        _text += '\n';
                    _text += text[i];
                }
                Vector2 size = MeasureTextEx(_font, _text.c_str(), _fontSize, 1);
                _sizeX = size.x;
                _sizeY = size.y;
            }

            void TextBox::draw()
            {
                DrawTextEx(_font, _text.c_str(), Vector2{_posX, _posY}, _fontSize, 1, _color);
            }
        }
    }
}