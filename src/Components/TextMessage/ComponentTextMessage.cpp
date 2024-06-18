/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextMessage
*/

#include "ComponentTextMessage.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            TextMessage::TextMessage(std::pair<int, int> pos, int width, std::string name, std::string text, int gap, Color color)
            {
                setRef();
                float refNameSize = 1.67;
                float refTextSize = 1.25;
                float nameSize = refNameSize * _refWidth / 100;
                float textSize = refTextSize * _refWidth / 100;
                _gap = gap;
                _name = std::make_unique<TextBox>(pos, width, name, nameSize, color, "supercell.ttf");
                _text = std::make_unique<TextBox>(std::make_pair(pos.first, pos.second + _name->getSizeY() + _gap), width, text, textSize, WHITE, "supercell.ttf");

                _refPosX = _name->getPosX() / _refWidth * 100;
                _refPosY = _name->getPosY() / _refHeight * 100;
                _refGap = _gap / _refHeight * 100;
            }

            void TextMessage::draw()
            {
                _name->draw();
                _text->draw();
            }

            void TextMessage::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _gap = _refGap * _refHeight / 100;
                _name->resize();
                _text->resize();
            }

            void TextMessage::setPosX(float x)
            {
                _name->setPosX(x);
                _text->setPosX(x);
            }

            void TextMessage::setPosY(float y)
            {
                _name->setPosY(y);
                _text->setPosY(y + _name->getSizeY() + _gap);
            }

            void TextMessage::modPosX(float x)
            {
                _name->modPosX(x);
                _text->modPosX(x);
            }

            void TextMessage::modPosY(float y)
            {
                _name->modPosY(y);
                _text->modPosY(y);
            }

            float TextMessage::getSizeX() const
            {
                float nameSizeX = _name->getSizeX();
                float textSizeX = _text->getSizeX();
                return nameSizeX > textSizeX ? nameSizeX : textSizeX;
            }

            float TextMessage::getSizeY() const
            {
                return _name->getSizeY() + _text->getSizeY() + _gap;
            }
        }
    }
}