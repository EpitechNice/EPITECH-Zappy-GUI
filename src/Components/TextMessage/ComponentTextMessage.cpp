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

            TextMessage::~TextMessage()
            {
                destroy();
            }

            void TextMessage::destroy()
            {
                if (!_isDestroyed) {
                    _name->destroy();
                    _text->destroy();
                    _isDestroyed = true;
                }
            }

            void TextMessage::setPosX(int x)
            {
                _name->setPosX(x);
                _text->setPosX(x);
            }

            void TextMessage::setPosY(int y)
            {
                _name->setPosY(y);
                _text->setPosY(y + _name->getSizeY() + _gap);
            }

            void TextMessage::setPos(std::pair<int, int> pos)
            {
                _name->setPosX(pos.first);
                _name->setPosY(pos.second);

                _text->setPosX(pos.first);
                _text->setPosY(pos.second + _name->getSizeY() + _gap);
            }

            std::pair<float, float> TextMessage::getSize() const
            {
                return std::make_pair(_name->getSizeX(), _name->getSizeY() + _text->getSizeY() + _gap);
            }

            void TextMessage::draw()
            {
                _name->draw();
                _text->draw();
            }
        }
    }
}