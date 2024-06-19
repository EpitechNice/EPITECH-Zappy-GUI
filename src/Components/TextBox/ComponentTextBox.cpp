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
                _sizeX = width;
                _text = text;
                _fontSize = fontSize;
                _color = color;

                setRef();

                _fontName = font;
                _font = Zappy::GUI::Raylib::FontManager::get()->getFont(font);
                setText(text);

                _refFontSize = _fontSize / _refWidth * 100;
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
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
                    if (MeasureTextEx(_font, tmp.c_str(), _fontSize, 1).x > _sizeX && i != 0)
                        _text += '\n';
                    _text += text[i];
                }
                Vector2 size = MeasureTextEx(_font, _text.c_str(), _fontSize, 1);
                _sizeY = size.y;
            }

            void TextBox::draw()
            {
                DrawTextEx(_font, _text.c_str(), Vector2{_posX, _posY}, _fontSize, 1, _color);
            }

            void TextBox::resize()
            {
                setRef();
                _font = Zappy::GUI::Raylib::FontManager::get()->getFont(_fontName);
                _fontSize = _refFontSize * _refWidth / 100;
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                setText(_text);
            }
        }
    }
}