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
                : _isDestroyed(false), _gap(gap)
            {
                _name = std::make_unique<TextBox>(pos, width, name, 20, color, "supercell.ttf");
                _text = std::make_unique<TextBox>(std::make_pair(pos.first, pos.second + _name->getSizeY() + _gap), width, text, 15, WHITE, "supercell.ttf");
            }

            void TextMessage::destroy()
            {
                if (_isDestroyed) return;
                _name->destroy();
                _text->destroy();
                _isDestroyed = true;
            }

            void TextMessage::draw()
            {
                _name->draw();
                _text->draw();
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