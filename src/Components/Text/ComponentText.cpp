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
            {
                _posX = pos.first;
                _posY = pos.second;
                _text = text;
                _fontSize = fontSize;
                _color = color;

                std::string path = "./assets/font/" + font;
                _font = LoadFont(path.c_str());
                setText(text);
            }

            void Text::destroy()
            {
                if (_isDestroyed) return;
                UnloadFont(_font);
                _isDestroyed = true;
            }

            void Text::draw()
            {
                DrawTextEx(_font, _text.c_str(), Vector2{_posX, _posY}, _fontSize, 1, _color);
            }


            void Text::setText(std::string text)
            {
                _text = text;
                Vector2 size = MeasureTextEx(_font, _text.c_str(), _fontSize, 1);
                _sizeX = size.x;
                _sizeY = size.y;
            }

            std::string Text::getText() const
            {
                return _text;
            }
        }
    }
}