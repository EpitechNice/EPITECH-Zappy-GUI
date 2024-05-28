/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentChatbox
*/

#include "ComponentChatbox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Chatbox::Chatbox()
                : _isDestroyed(false)
            {
                int height = GetScreenHeight();
                _width = GetScreenWidth() / 3;
                int heightPart = height / 8;

                _rectTop = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, height), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(-_width, height - heightPart), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectTop->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), ">", 30, ORANGE);
                _openButton->disableBubble();
                std::pair<float, float> buttonSize = _openButton->getSize();
                _openButton->setPos(std::make_pair(8, height / 2 - buttonSize.second / 2));
                _open = false;

                _textMessage = std::make_unique<TextMessage>(std::make_pair(-_width  + 10, heightPart + 10), _width - 20, "Lorem Ipsum", "sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 5, (Color){207, 205, 164, 255});
            }

            Chatbox::~Chatbox()
            {
                if (!_isDestroyed)
                    destroy();
            }


            void Chatbox::destroy()
            {
                _openButton->destroy();
                _textMessage->destroy();
            }


            void Chatbox::draw()
            {
                _rectMid->draw();
                _rectTop->draw();
                _rectBot->draw();
                _openButton->draw();
                _textMessage->draw();
            }

            void Chatbox::update()
            {
                if (_openButton->isClicked())
                    (_open) ? _setChatboxClose() : _setChatboxOpen();
            }


            void Chatbox::_setChatboxOpen()
            {
                _rectTop->setPosX(0);
                _rectMid->setPosX(0);
                _rectBot->setPosX(0);
                _openButton->setPosX(_width + 8);
                _openButton->setText("<");

                _textMessage->setPosX(10);
                _open = true;
            }

            void Chatbox::_setChatboxClose()
            {
                _rectTop->setPosX(-_width);
                _rectMid->setPosX(-_width);
                _rectBot->setPosX(-_width);
                _openButton->setPosX(8);
                _openButton->setText(">");

                _textMessage->setPosX(-_width + 10);
                _open = false;
            }
        }
    }
}